/*
 * soundfx.cpp
 * GnollHack for Windows Sound Effects Using FMOD
 *
 * Copyright (c) Janne Gustafsson, 2020
 *
 */

#include <windows.h>
#include "fmod_studio.hpp"
#include "fmod.hpp"
#include "resource.h"
#include "soundset.h"

using namespace FMOD;
static System* fmod_core_system = (System*)0;
static Studio::System* fmod_studio_system = (Studio::System*)0;

struct GNHSoundInstance {
    Studio::EventInstance* eventInstance;
    enum ghsound_types ghsound;
    float normalVolume;
    int sound_type;
    struct GNHSoundInstance* next_instance;
};

#define NUM_IMMEDIATE_SOUND_INSTANCES 16

static GNHSoundInstance musicInstances[2] = { 0 };
static GNHSoundInstance levelAmbientInstances[2] = { 0 };
static GNHSoundInstance occupationAmbientInstances[2] = { 0 };
static GNHSoundInstance effectAmbientInstances[2] = { 0 };
static GNHSoundInstance immediateSoundInstances[NUM_IMMEDIATE_SOUND_INSTANCES] = { 0 };
static GNHSoundInstance* ambient_base = NULL; /* for sound source ambients */

static float general_volume = 1.0f;
static float general_music_volume = 1.0f;
static float general_ambient_volume = 1.0f;
static float general_sfx_volume = 1.0f;
static float general_ui_volume = 1.0f;

/* GHSound -> FMOD event mapping here */
enum sound_bank_types {
    SOUND_BANK_NONE = 0,
    SOUND_BANK_MASTER,
    MAX_SOUND_BANKS
};

struct sound_bank_definition {
    boolean isresource;
    int resource_id;
    const char* filename;
};


struct ghsound_eventmapping {
    enum sound_bank_types bank_id;
    const char* eventPath;
    float volume;
};


#define NoSound { SOUND_BANK_NONE,  "", 0.0f}

const struct ghsound_eventmapping ghsound2event[MAX_GHSOUNDS] = {
    { SOUND_BANK_NONE, "" , 0.0f },
    { SOUND_BANK_MASTER, "event:/Music/Music-Splash", 0.5f},
    { SOUND_BANK_MASTER, "event:/Music/Music-Player-Selection", 0.3f},
    { SOUND_BANK_MASTER, "event:/Music/Music-Intro", 0.1f},
    { SOUND_BANK_MASTER, "event:/Music/Music-Normal-1", BACKGROUND_MUSIC_VOLUME},
    { SOUND_BANK_MASTER, "event:/Music/Music-Oracle", BACKGROUND_MUSIC_VOLUME},
    { SOUND_BANK_MASTER, "event:/Music/Music-Temple", BACKGROUND_MUSIC_VOLUME},
    { SOUND_BANK_MASTER, "event:/Music/Music-Medusa", BACKGROUND_MUSIC_VOLUME},
    { SOUND_BANK_MASTER, "event:/Music/Music-Castle", BACKGROUND_MUSIC_VOLUME},
    { SOUND_BANK_MASTER, "event:/Music/Music-Gnomish-Mines-Normal", 0.07f},
    { SOUND_BANK_MASTER, "event:/Music/Music-Gnomish-Mines-Town", 0.10f},
    
    { SOUND_BANK_MASTER, "event:/Music/Music-Sokoban-Normal", 0.10f},
    { SOUND_BANK_MASTER, "event:/Music/Music-Gehennom-Normal", 0.12f},
    { SOUND_BANK_MASTER, "event:/Music/Music-Gehennom-Valley", 0.08f},
    { SOUND_BANK_MASTER, "event:/Music/Music-Gehennom-Sanctum", 0.08f},
    { SOUND_BANK_MASTER, "event:/Music/Game Over", 0.1f},
    { SOUND_BANK_MASTER, "event:/Music/Shop/Normal", 0.07f},
    { SOUND_BANK_MASTER, "event:/Music/Shop/Angry", BACKGROUND_MUSIC_VOLUME},
    { SOUND_BANK_MASTER, "event:/Music/Shop/Dead", BACKGROUND_MUSIC_VOLUME},
    { SOUND_BANK_MASTER, "event:/Music/Shop/Deserted", BACKGROUND_MUSIC_VOLUME},
    { SOUND_BANK_MASTER, "event:/Location/Fountain/Fountain Ambient" , 0.75f},

    { SOUND_BANK_MASTER, "event:/Monster/Bee/Bee Ambient" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Location/Altar/Fire Ambient" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Quarterstaff/Quarterstaff Swing" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Quarterstaff/Quarterstaff Hit" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Level/Valley Ambient" , 0.10f},
    { SOUND_BANK_MASTER, "event:/Ambience/Room/Morgue Ambient" , 0.10f},
    { SOUND_BANK_MASTER, "event:/Ambience/Room/Garden Ambient" , 0.03f},
    { SOUND_BANK_MASTER, "event:/UI/Button Down" , 0.15f},
    { SOUND_BANK_MASTER, "event:/UI/Menu Select" , 0.15f},
    { SOUND_BANK_MASTER, "event:/SFX/Action/Quaff" , 1.0f},

    { SOUND_BANK_MASTER, "event:/Location/Poison Gas/Poison Gas" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Ray/Electricity/Ray Electricity Ambient" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Ray/Electricity/Ray Electricity Create" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Ray/Electricity/Ray Electricity Destroy" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Ray/Electricity/Ray Electricity Bounce" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Bow/Bow Fire" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Arrow/Arrow Hit" , 4.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Sword/Sword Swing" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Sword/Sword Hit" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Axe/Axe Swing" , 1.0f},
    
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Axe/Axe Hit" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Monster/Goblin/Goblin Death" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Dagger/Dagger Swing" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Dagger/Dagger Hit" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Monster/Human/Barehanded/Human Barehanded Swing" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Monster/Human/Barehanded/Human Barehanded Hit" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Monster/Human/Barefooted/Human Kick Swing" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Monster/Human/Barefooted/Human Kick Hit" , 1.0f},
    { SOUND_BANK_MASTER, "event:/SFX/Door/Door Wham" , 1.0f},
    { SOUND_BANK_MASTER, "event:/SFX/Door/Door Break" , 1.0f},

    { SOUND_BANK_MASTER, "event:/SFX/Door/Door Open" , 0.1f},
    { SOUND_BANK_MASTER, "event:/SFX/Door/Door Close" , 0.5f},
    { SOUND_BANK_MASTER, "event:/SFX/Door/Door Unlock" , 0.5f},
    { SOUND_BANK_MASTER, "event:/SFX/Door/Door Lock" , 0.5f},
    { SOUND_BANK_MASTER, "event:/SFX/Door/Door Resists" , 0.5f},
    { SOUND_BANK_MASTER, "event:/SFX/Door/Door Try Locked" , 0.5f},
    { SOUND_BANK_MASTER, "event:/Object/Tool/Chest/Chest Unlock" , 0.5f},
    { SOUND_BANK_MASTER, "event:/Object/Tool/Chest/Chest Lock" , 0.5f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Crossbow/Crossbow Fire" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/General/Coin/Coins Pick Up" , 1.0f},

    { SOUND_BANK_MASTER, "event:/Object/General/Coin/Coins Drop" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Monster/Horse/Barefooted/Horse Footsteps" , 0.15f},
    { SOUND_BANK_MASTER, "event:/Object/General/Boulder/Push Boulder" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Monster/Human/Male/Push Effort" , 0.25f},
    { SOUND_BANK_MASTER, "event:/SFX/Special Attack/Cause Paralysis" , 1.0f},
    { SOUND_BANK_MASTER, "event:/SFX/Special Attack/Cause Sleeping" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Monster/Generic/Generic Monster Death" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Tool/Chest/Chest Lock Break" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Tool/Chest/Chest Lid Slam" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/General/Generic/Generic Item Pick Up" , 0.3f},

    { SOUND_BANK_MASTER, "event:/Object/General/Generic/Generic Item Drop" , 0.5f},
    { SOUND_BANK_MASTER, "event:/Object/General/Generic/Generic Item Throw" , 0.5f},
    { SOUND_BANK_MASTER, "event:/Object/Armor/Cotton Slippers/Cotton Slipper Footsteps" , 0.1f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Sword/Sword Drop" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Weapon/Dagger/Dagger Drop" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/General/Generic/Generic Fly" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/General/Generic/Generic Levitate" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/General/Generic/Generic Discard" , 0.5f},
    { SOUND_BANK_MASTER, "event:/Object/General/Generic/Generic Sparks Fly" , 1.0f},
    { SOUND_BANK_MASTER, "event:/Object/Food/Apple/Apple Eat" , 0.5f},

    { SOUND_BANK_MASTER, "event:/Object/Food/Carrot/Carrot Eat" , 0.5f},
    { SOUND_BANK_MASTER, "event:/Monster/Human/Barefooted/Player Footsteps", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Eating/Eating Ambient", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Eating/Eating Start", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Eating/Eating Finish", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Eating/Eating Interrupted", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Eating/Eating Resume", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging/Digging Ambient", 1.0f },
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging/Digging Start", 1.0f },
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging/Digging Finish", 1.0f },

    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging/Digging Interrupted", 1.0f },
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging/Digging Resume", 1.0f },
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging Ground/Digging Ground Ambient", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging Ground/Digging Ground Start", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging Ground/Digging Ground Finish", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging Ground/Digging Ground Interrupted", 1.0f},
    { SOUND_BANK_MASTER, "event:/Ambience/Occupation/Digging Ground/Digging Ground Resume", 1.0f},
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Desecrate Altar", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/General/Summon Demon", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Sacrifice Pet", 1.0f },

    { SOUND_BANK_MASTER, "event:/SFX/Altar/Sacrifice Coaligned Unicorn", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Add Alignment", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Environment/Thunderclap", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Environment/Charged Air", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Accepts Sacrifice", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Rejects Sacrifice", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Power Increase", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Power Decrease", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/God Mollified", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Inadequacy", 1.0f },

    { SOUND_BANK_MASTER, "event:/SFX/Altar/Absolved", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Hopeful Feeling", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Reconciliation", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Gift", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Four-Leaf Clover", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/General/Aura Glow", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Offering Burst of Flame", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Altar/Offering Vanish", 1.0f },
    { SOUND_BANK_MASTER, "event:/Monster/Dog/Dog Yelp", 1.0f },
    { SOUND_BANK_MASTER, "event:/Monster/Dog/Dog Warn Cursed", 1.0f },

    { SOUND_BANK_MASTER, "event:/Monster/Cat/Cat Yelp", 1.0f },
    { SOUND_BANK_MASTER, "event:/Monster/Cat/Cat Warn Cursed", 1.0f },
    { SOUND_BANK_MASTER, "event:/Monster/Generic/Generic Yelp", 1.0f },
    { SOUND_BANK_MASTER, "event:/Monster/Generic/Generic Warn Cursed", 1.0f },
    { SOUND_BANK_MASTER, "event:/Monster/Generic/Generic Pray", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Fail", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Pleased", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Fix All Troubles", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Fix One Trouble", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Repair", 1.0f },

    { SOUND_BANK_MASTER, "event:/SFX/Pray/Healing", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Uncurse", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Gift", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Crowning", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Spellbook", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Bless Water", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Curse Water", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Pray/Shimmering Light", 1.0f },
    { SOUND_BANK_MASTER, "event:/Ray/Camera Flash/Camera Flash Ambient", 1.0f },
    { SOUND_BANK_MASTER, "event:/Ray/Camera Flash/Camera Flash Create", 1.0f },

    { SOUND_BANK_MASTER, "event:/Music/Quest-Normal", BACKGROUND_MUSIC_VOLUME },
    { SOUND_BANK_MASTER, "event:/Music/Vlad-Tower-Normal", 0.08f },
    { SOUND_BANK_MASTER, "event:/Music/Modron-Normal", BACKGROUND_MUSIC_VOLUME },
    { SOUND_BANK_MASTER, "event:/Music/Bovine-Normal", BACKGROUND_MUSIC_VOLUME },
    { SOUND_BANK_MASTER, "event:/Music/End Game/Normal", 0.08f },
    { SOUND_BANK_MASTER, "event:/Music/End Game/Earth", 0.08f },
    { SOUND_BANK_MASTER, "event:/Music/End Game/Air", 0.08f },
    { SOUND_BANK_MASTER, "event:/Music/End Game/Water", 0.08f },
    { SOUND_BANK_MASTER, "event:/Music/End Game/Fire", 0.08f },
    { SOUND_BANK_MASTER, "event:/Music/End Game/Astral", 0.08f },

    { SOUND_BANK_MASTER, "event:/Music/Victory", 0.20f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Success", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Blessed Success", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Uncurse and Other", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Negative", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Violent Glow", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Vibrate Warning", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Vibrate and Destroy", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Special Success", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/Special Negative", 1.0f },

    { SOUND_BANK_MASTER, "event:/SFX/Spell/Enchant Item/General Fail", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/General/Hands Itch", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Protect Item/Success", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Protect Item/Fail", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Repair Item/Success", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Repair Item/Fail", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Bless Item/Success", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Bless Item/Fail", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Curse Item/Success", 1.0f },
    { SOUND_BANK_MASTER, "event:/SFX/Spell/Curse Item/Fail", 1.0f },
};


#undef NoSound


extern "C" 
{
    boolean
    initialize_fmod_studio()
    {
        void* extraDriverData = NULL;

        Studio::System::create(&fmod_studio_system);

        fmod_studio_system->getCoreSystem(&fmod_core_system);
        fmod_core_system->setSoftwareFormat(0, FMOD_SPEAKERMODE_DEFAULT, 0);

        FMOD_RESULT result = fmod_studio_system->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, extraDriverData);

        boolean res = (result == FMOD_OK);
        return res;
    }

    boolean
    load_fmod_banks()
    {
        FMOD_RESULT       result;
        FMOD::Studio::Bank* bank[2] = { 0 };
        HINSTANCE hResInstance = (HINSTANCE)GetModuleHandle(NULL);

        for (int i = 0; i < 2; i++)
        {
            int rid[2] = { IDR_RCDATA_MASTER, IDR_RCDATA_STRINGS };
            HRSRC res = FindResource(hResInstance, MAKEINTRESOURCE(rid[i]), RT_RCDATA);

            if (res)
            {
                HGLOBAL mem = LoadResource(hResInstance, res);
                void* data = LockResource(mem);
                size_t len = SizeofResource(hResInstance, res);

                result = fmod_studio_system->loadBankMemory((const char*)data, (int)len, FMOD_STUDIO_LOAD_MEMORY, FMOD_STUDIO_LOAD_BANK_NORMAL, &bank[i]);
                if (result != FMOD_OK)
                    return FALSE;
            }
        }

        return TRUE;
    }

    void
    close_fmod_studio()
    {
        FMOD_RESULT result;

        result = fmod_studio_system->unloadAll();
        result = fmod_studio_system->release();

        fmod_studio_system = (Studio::System*)0;
    }

    boolean 
    fmod_play_music(struct ghsound_music_info info)
    {
        FMOD_RESULT result;

        enum ghsound_types soundid = info.ghsound;
        if (soundid == GHSOUND_NONE)
        {
            if (musicInstances[0].eventInstance && musicInstances[0].normalVolume > 0.0f)
            {
                /* Stop music */
                result = musicInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                if (result != FMOD_OK)
                    return FALSE;
                musicInstances[0].normalVolume = 0.0f;
                result = fmod_studio_system->update();
                return (result == FMOD_OK);
            }

            /* Nothing to do */
            return TRUE;
        }


        struct ghsound_eventmapping eventmap = ghsound2event[soundid];
        float event_volume = eventmap.volume;

        if (!eventmap.eventPath || !strcmp(eventmap.eventPath, ""))
            return FALSE;

        Studio::EventDescription* musicDescription = NULL;
        result = fmod_studio_system->getEvent(eventmap.eventPath, &musicDescription);

        if (result != FMOD_OK)
            return FALSE;

        if (musicInstances[0].eventInstance)
        {
            Studio::EventInstance* earlierMusicInstance = musicInstances[0].eventInstance;
            Studio::EventDescription* earlierMusicDescription = NULL;
            earlierMusicInstance->getDescription(&earlierMusicDescription);
            if (earlierMusicDescription && musicDescription == earlierMusicDescription)
            {
                /* Already playing, just check the difference in volume */
                if (musicInstances[0].normalVolume == 0.0f && info.volume > 0.0f)
                {
                    /* Restart the music and adjust volume */
                    result = musicInstances[0].eventInstance->setVolume(min(1.0f, info.volume * event_volume * general_music_volume * general_volume));
                    if (result != FMOD_OK)
                        return FALSE;

                    result = musicInstances[0].eventInstance->start();
                    if (result != FMOD_OK)
                        return FALSE;
                }
                else if (musicInstances[0].normalVolume > 0.0f && info.volume == 0.0f)
                {
                    /* Stop music */
                    result = musicInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                    if (result != FMOD_OK)
                        return FALSE;
                }
                else if (musicInstances[0].normalVolume != info.volume)
                {
                    /* Adjust volume */
                    result = musicInstances[0].eventInstance->setVolume(min(1.0f, info.volume * event_volume * general_music_volume * general_volume));
                    if (result != FMOD_OK)
                        return FALSE;
                }

                /* Finally, update */
                if (musicInstances[0].normalVolume != info.volume)
                {
                    musicInstances[0].normalVolume = info.volume;
                    result = fmod_studio_system->update();
                    if (result != FMOD_OK)
                        return FALSE;
                }

                return TRUE;
            }
        }

        /* Not playing yet, so make a new instance */
        Studio::EventInstance* musicInstance = NULL;
        result = musicDescription->createInstance(&musicInstance);
        if (result != FMOD_OK)
            return FALSE;

        musicInstance->setVolume(min(1.0f, info.volume * event_volume * general_music_volume * general_volume));
        if (info.volume > 0.0f)
        {
            result = musicInstance->start();
            if (result != FMOD_OK)
                return FALSE;
        }

        /* If starting succeeded, stop the old music in musicInstances[0] by fading */
        if (musicInstances[0].eventInstance)
        {
            musicInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);

            /* move to musicInstances[1] for later release, and before that, release existing musicInstances[1] */
            if (musicInstances[1].eventInstance)
                musicInstances[1].eventInstance->release();

            musicInstances[1].eventInstance = musicInstances[0].eventInstance;
            musicInstances[1].ghsound = musicInstances[0].ghsound;
            musicInstances[1].normalVolume = musicInstances[0].normalVolume;
            musicInstances[1].sound_type = musicInstances[0].sound_type;
        }

        /* Set the new instance as musicInstances[0] */
        musicInstances[0].eventInstance = musicInstance;
        musicInstances[0].ghsound = info.ghsound;
        musicInstances[0].normalVolume = info.volume;
        musicInstances[0].sound_type = 0;

        result = fmod_studio_system->update();
        return (result == FMOD_OK);
    }


    boolean
    fmod_play_level_ambient_sound(struct ghsound_level_ambient_info info)
    {
        FMOD_RESULT result;

        enum ghsound_types soundid = info.ghsound;

        if (soundid == GHSOUND_NONE)
        {
            if (levelAmbientInstances[0].eventInstance && levelAmbientInstances[0].normalVolume > 0.0f)
            {
                /* Stop ambient sound */
                result = levelAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                if (result != FMOD_OK)
                    return FALSE;
                levelAmbientInstances[0].normalVolume = 0.0f;
                result = fmod_studio_system->update();
                return (result == FMOD_OK);
            }

            /* Nothing to do */
            return TRUE;
        }

        struct ghsound_eventmapping eventmap = ghsound2event[soundid];
        float event_volume = eventmap.volume;

        if (!eventmap.eventPath || !strcmp(eventmap.eventPath, ""))
            return FALSE;

        Studio::EventDescription* occupationAmbientDescription = NULL;
        result = fmod_studio_system->getEvent(eventmap.eventPath, &occupationAmbientDescription);

        if (result != FMOD_OK)
            return FALSE;

        if (levelAmbientInstances[0].eventInstance)
        {
            Studio::EventInstance* earlierLevelAmbientInstance = levelAmbientInstances[0].eventInstance;
            Studio::EventDescription* earlierLevelAmbientDescription = NULL;
            earlierLevelAmbientInstance->getDescription(&earlierLevelAmbientDescription);
            if (earlierLevelAmbientDescription && occupationAmbientDescription == earlierLevelAmbientDescription)
            {
                /* Already playing, just check the difference in volume */
                if (levelAmbientInstances[0].normalVolume == 0.0f && info.volume > 0.0f)
                {
                    /* Restart the sound and adjust volume */
                    result = levelAmbientInstances[0].eventInstance->setVolume(min(1.0f, info.volume * event_volume * general_ambient_volume * general_volume));
                    if (result != FMOD_OK)
                        return FALSE;

                    result = levelAmbientInstances[0].eventInstance->start();
                    if (result != FMOD_OK)
                        return FALSE;
                }
                else if (levelAmbientInstances[0].normalVolume > 0.0f && info.volume == 0.0f)
                {
                    /* Stop ambient sound */
                    result = levelAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                    if (result != FMOD_OK)
                        return FALSE;
                }
                else if (levelAmbientInstances[0].normalVolume != info.volume)
                {
                    /* Adjust volume */
                    result = levelAmbientInstances[0].eventInstance->setVolume(min(1.0f, info.volume * event_volume * general_ambient_volume * general_volume));
                    if (result != FMOD_OK)
                        return FALSE;
                }

                /* Finally, update */
                if (levelAmbientInstances[0].normalVolume != info.volume)
                {
                    levelAmbientInstances[0].normalVolume = info.volume;
                    result = fmod_studio_system->update();
                    if (result != FMOD_OK)
                        return FALSE;
                }

                return TRUE;
            }
        }

        /* Not playing yet, so make a new instance */
        Studio::EventInstance* levelAmbientInstance = NULL;
        result = occupationAmbientDescription->createInstance(&levelAmbientInstance);
        if (result != FMOD_OK)
            return FALSE;

        result = levelAmbientInstance->setVolume(min(1.0f, info.volume * event_volume * general_ambient_volume * general_volume));
        if (result != FMOD_OK)
            return FALSE;

        if (info.volume > 0.0f)
        {
            result = levelAmbientInstance->start();
            if (result != FMOD_OK)
                return FALSE;
        }
        /* If starting succeeded, stop the old ambient sound in levelAmbientInstances[0] by fading */
        if (levelAmbientInstances[0].eventInstance)
        {
            if(levelAmbientInstances[0].ghsound != GHSOUND_NONE)
                levelAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);

            /* move to levelAmbientInstances[1] for later release, and before that, release existing levelAmbientInstances[1] */
            if (levelAmbientInstances[1].eventInstance)
                levelAmbientInstances[1].eventInstance->release();

            levelAmbientInstances[1].eventInstance = levelAmbientInstances[0].eventInstance;
            levelAmbientInstances[1].ghsound = levelAmbientInstances[0].ghsound;
            levelAmbientInstances[1].normalVolume = levelAmbientInstances[0].normalVolume;
            levelAmbientInstances[1].sound_type = levelAmbientInstances[0].sound_type;
        }

        /* Set the new instance as levelAmbientInstances[0] */
        levelAmbientInstances[0].eventInstance = levelAmbientInstance;
        levelAmbientInstances[0].ghsound = info.ghsound;
        levelAmbientInstances[0].normalVolume = info.volume;
        levelAmbientInstances[0].sound_type = 0;

        result = fmod_studio_system->update();
        return (result == FMOD_OK);
    }


    boolean
    fmod_play_occupation_ambient_sound(struct ghsound_occupation_ambient_info info)
    {
        FMOD_RESULT result;

        enum ghsound_types soundid = info.ghsound;

        if (soundid == GHSOUND_NONE)
        {
            if (occupationAmbientInstances[0].eventInstance && occupationAmbientInstances[0].normalVolume > 0.0f)
            {
                /* Stop ambient sound */
                result = occupationAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                if (result != FMOD_OK)
                    return FALSE;
                occupationAmbientInstances[0].normalVolume = 0.0f;
                result = fmod_studio_system->update();
                return (result == FMOD_OK);
            }

            /* Nothing to do */
            return TRUE;
        }

        struct ghsound_eventmapping eventmap = ghsound2event[soundid];
        float event_volume = eventmap.volume;

        if (!eventmap.eventPath || !strcmp(eventmap.eventPath, ""))
            return FALSE;

        Studio::EventDescription* occupationAmbientDescription = NULL;
        result = fmod_studio_system->getEvent(eventmap.eventPath, &occupationAmbientDescription);

        if (result != FMOD_OK)
            return FALSE;

        if (occupationAmbientInstances[0].eventInstance)
        {
            Studio::EventInstance* earlierOccupationAmbientInstance = occupationAmbientInstances[0].eventInstance;
            Studio::EventDescription* earlierOccupationAmbientDescription = NULL;
            earlierOccupationAmbientInstance->getDescription(&earlierOccupationAmbientDescription);
            if (earlierOccupationAmbientDescription && occupationAmbientDescription == earlierOccupationAmbientDescription)
            {
                /* Already playing, just check the difference in volume */
                if (occupationAmbientInstances[0].normalVolume == 0.0f && info.volume > 0.0f)
                {
                    /* Restart the sound and adjust volume */
                    result = occupationAmbientInstances[0].eventInstance->setVolume(min(1.0f, info.volume * event_volume * general_ambient_volume * general_volume));
                    if (result != FMOD_OK)
                        return FALSE;

                    result = occupationAmbientInstances[0].eventInstance->start();
                    if (result != FMOD_OK)
                        return FALSE;
                }
                else if (occupationAmbientInstances[0].normalVolume > 0.0f && info.volume == 0.0f)
                {
                    /* Stop ambient sound */
                    result = occupationAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                    if (result != FMOD_OK)
                        return FALSE;
                }
                else if (occupationAmbientInstances[0].normalVolume != info.volume)
                {
                    /* Adjust volume */
                    result = occupationAmbientInstances[0].eventInstance->setVolume(min(1.0f, info.volume * event_volume * general_ambient_volume * general_volume));
                    if (result != FMOD_OK)
                        return FALSE;
                }

                /* Finally, update */
                if (occupationAmbientInstances[0].normalVolume != info.volume)
                {
                    occupationAmbientInstances[0].normalVolume = info.volume;
                    result = fmod_studio_system->update();
                    if (result != FMOD_OK)
                        return FALSE;
                }

                return TRUE;
            }
        }

        /* Not playing yet, so make a new instance */
        Studio::EventInstance* occupationAmbientInstance = NULL;
        result = occupationAmbientDescription->createInstance(&occupationAmbientInstance);
        if (result != FMOD_OK)
            return FALSE;

        result = occupationAmbientInstance->setVolume(min(1.0f, info.volume * event_volume * general_ambient_volume * general_volume));
        if (result != FMOD_OK)
            return FALSE;

        if (info.volume > 0.0f)
        {
            result = occupationAmbientInstance->start();
            if (result != FMOD_OK)
                return FALSE;
        }
        /* If starting succeeded, stop the old ambient sound in occupationAmbientInstances[0] by fading */
        if (occupationAmbientInstances[0].eventInstance)
        {
            if (occupationAmbientInstances[0].ghsound != GHSOUND_NONE)
                occupationAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);

            /* move to occupationAmbientInstances[1] for later release, and before that, release existing occupationAmbientInstances[1] */
            if (occupationAmbientInstances[1].eventInstance)
                occupationAmbientInstances[1].eventInstance->release();

            occupationAmbientInstances[1].eventInstance = occupationAmbientInstances[0].eventInstance;
            occupationAmbientInstances[1].ghsound = occupationAmbientInstances[0].ghsound;
            occupationAmbientInstances[1].normalVolume = occupationAmbientInstances[0].normalVolume;
            occupationAmbientInstances[1].sound_type = occupationAmbientInstances[0].sound_type;
        }

        /* Set the new instance as occupationAmbientInstances[0] */
        occupationAmbientInstances[0].eventInstance = occupationAmbientInstance;
        occupationAmbientInstances[0].ghsound = info.ghsound;
        occupationAmbientInstances[0].normalVolume = info.volume;
        occupationAmbientInstances[0].sound_type = 0;

        result = fmod_studio_system->update();
        return (result == FMOD_OK);
    }




    boolean
    fmod_set_effect_ambient_volume(struct effect_ambient_volume_info info)
    {
        FMOD_RESULT result;
        if (effectAmbientInstances[0].eventInstance)
        {
            struct ghsound_eventmapping eventmap = ghsound2event[effectAmbientInstances[0].ghsound];
            float event_volume = eventmap.volume;
            float volume = info.volume;

            /* Adjust volume */
            effectAmbientInstances[0].eventInstance->setVolume(min(1.0f, volume * event_volume * general_sfx_volume * general_volume));

            if (volume == 0.0f && effectAmbientInstances[0].normalVolume > 0.0f)
            {
                /* Stop ambient */
                result = effectAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                if (result != FMOD_OK)
                    return FALSE;
            }
            else if (volume > 0.0f && effectAmbientInstances[0].normalVolume == 0.0f)
            {
                /* Start ambient */
                result = effectAmbientInstances[0].eventInstance->start();
                if (result != FMOD_OK)
                    return FALSE;

            }

            effectAmbientInstances[0].normalVolume = volume;
            result = fmod_studio_system->update();
            return (result == FMOD_OK);
        }

        /* Nothing's playing */
        return FALSE;
    }

    boolean
    fmod_play_effect_ambient_sound(struct ghsound_effect_ambient_info info)
    {
        FMOD_RESULT result;

        enum ghsound_types soundid = info.ghsound;

        if (soundid == GHSOUND_NONE)
        {
            if (effectAmbientInstances[0].eventInstance)
            {
                /* Stop ambient sound */
                result = effectAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                if (result != FMOD_OK)
                    return FALSE;
                effectAmbientInstances[0].ghsound = GHSOUND_NONE;
                effectAmbientInstances[0].normalVolume = 0.0f;
                effectAmbientInstances[0].sound_type = 0;
                result = fmod_studio_system->update();
                return (result == FMOD_OK);
            }

            /* Nothing to do */
            return TRUE;
        }

        struct ghsound_eventmapping eventmap = ghsound2event[soundid];
        float event_volume = eventmap.volume;

        if (!eventmap.eventPath || !strcmp(eventmap.eventPath, ""))
            return FALSE;

        Studio::EventDescription* effectAmbientDescription = NULL;
        result = fmod_studio_system->getEvent(eventmap.eventPath, &effectAmbientDescription);

        if (result != FMOD_OK)
            return FALSE;

        if (effectAmbientInstances[0].eventInstance)
        {
            Studio::EventInstance* earlierEffectAmbientInstance = effectAmbientInstances[0].eventInstance;
            Studio::EventDescription* earlierEffectAmbientDescription = NULL;
            earlierEffectAmbientInstance->getDescription(&earlierEffectAmbientDescription);
            if (earlierEffectAmbientDescription && effectAmbientDescription == earlierEffectAmbientDescription)
            {
                /* Already selected, but may be stopped; just set the volume, which may start or stop the ambient */
                struct effect_ambient_volume_info vinfo = { 0 };
                vinfo.volume = info.volume;
                return fmod_set_effect_ambient_volume(vinfo);
            }
        }

        /* Not playing yet, so make a new instance */
        Studio::EventInstance* effectAmbientInstance = NULL;
        result = effectAmbientDescription->createInstance(&effectAmbientInstance);
        if (result != FMOD_OK)
            return FALSE;

        /* Note: effect ambient uses sfx volume instead of ambient volume */
        effectAmbientInstance->setVolume(min(1.0f, info.volume * event_volume * general_sfx_volume * general_volume));
        if (info.volume > 0.0f)
        {
            result = effectAmbientInstance->start();
            if (result != FMOD_OK)
                return FALSE;
        }

        /* If starting succeeded, stop the old ambient sound in effectAmbientInstances[0] by fading */
        if (effectAmbientInstances[0].eventInstance)
        {
            if (effectAmbientInstances[0].ghsound != GHSOUND_NONE && effectAmbientInstances[0].normalVolume > 0.0f)
                effectAmbientInstances[0].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);

            /* move to effectAmbientInstances[1] for later release, and before that, release existing effectAmbientInstances[1] */
            if (effectAmbientInstances[1].eventInstance)
                effectAmbientInstances[1].eventInstance->release();

            effectAmbientInstances[1].eventInstance = effectAmbientInstances[0].eventInstance;
            effectAmbientInstances[1].ghsound = effectAmbientInstances[0].ghsound;
            effectAmbientInstances[1].normalVolume = effectAmbientInstances[0].normalVolume;
            effectAmbientInstances[1].sound_type = effectAmbientInstances[0].sound_type;
        }

        /* Set the new instance as effectAmbientInstances[0] */
        effectAmbientInstances[0].eventInstance = effectAmbientInstance;
        effectAmbientInstances[0].ghsound = info.ghsound;
        effectAmbientInstances[0].normalVolume = info.volume;
        effectAmbientInstances[0].sound_type = 0;

        result = fmod_studio_system->update();
        return (result == FMOD_OK);
    }

    boolean
    fmod_play_immediate_sound(struct ghsound_immediate_info info)
    {
        FMOD_RESULT result;

        enum ghsound_types soundid = info.ghsound;
        struct ghsound_eventmapping eventmap = ghsound2event[soundid];
        float event_volume = eventmap.volume;
        if (!eventmap.eventPath || !strcmp(eventmap.eventPath, ""))
            return FALSE;
        float relevant_general_volume = (info.sound_type == IMMEDIATE_SOUND_UI ? general_ui_volume : general_sfx_volume);

        Studio::EventDescription* immediateSoundDescription = NULL;
        result = fmod_studio_system->getEvent(eventmap.eventPath, &immediateSoundDescription);
        if (result != FMOD_OK)
            return FALSE;

        Studio::EventInstance* immediateSoundInstance = NULL;
        result = immediateSoundDescription->createInstance(&immediateSoundInstance);
        if (result != FMOD_OK)
            return FALSE;

        /* Set volume */
        result = immediateSoundInstance->setVolume(min(1.0f, info.volume * event_volume * relevant_general_volume * general_volume));
        if (result != FMOD_OK)
            return FALSE;

        if (result != FMOD_OK)
            return FALSE;

        /* Set parameters */
        FMOD_STUDIO_PARAMETER_DESCRIPTION paramDesc;
        for (int i = 0; i < MAX_SOUND_PARAMETERS; i++)
        {
            if(!info.parameter_names[i] || strcmp(info.parameter_names[i], "") == 0)
                break;

            result = immediateSoundDescription->getParameterDescriptionByName(info.parameter_names[i], &paramDesc);
            if (result != FMOD_OK)
                return FALSE;

            FMOD_STUDIO_PARAMETER_ID paramID = paramDesc.id;
            float parameterValue = info.parameter_values[i];
            result = immediateSoundInstance->setParameterByID(paramID, parameterValue);
            if (result != FMOD_OK)
                return FALSE;
        }

        /* Play sound */
        result = immediateSoundInstance->start();
        if (result != FMOD_OK)
            return FALSE;

        if (immediateSoundInstances[0].eventInstance)
        {
            /* Delete the last one */
            if (immediateSoundInstances[NUM_IMMEDIATE_SOUND_INSTANCES - 1].eventInstance)
            {
                /* Stop playing just in case */
                immediateSoundInstances[NUM_IMMEDIATE_SOUND_INSTANCES - 1].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
                /* Release */
                immediateSoundInstances[NUM_IMMEDIATE_SOUND_INSTANCES - 1].eventInstance->release();
            }

            /* Move all others back */
            for (int i = NUM_IMMEDIATE_SOUND_INSTANCES - 1; i >= 1; i--)
            {
                immediateSoundInstances[i].eventInstance = immediateSoundInstances[i - 1].eventInstance;
                immediateSoundInstances[i].ghsound = immediateSoundInstances[i - 1].ghsound;
                immediateSoundInstances[i].normalVolume = immediateSoundInstances[i - 1].normalVolume;
                immediateSoundInstances[i].sound_type = immediateSoundInstances[i - 1].sound_type;
            }
        }

        /* Set the new instance as movementInstances[0] */
        immediateSoundInstances[0].eventInstance = immediateSoundInstance;
        immediateSoundInstances[0].ghsound = info.ghsound;
        immediateSoundInstances[0].normalVolume = info.volume;
        immediateSoundInstances[0].sound_type = info.sound_type;

        result = fmod_studio_system->update();
        if (result != FMOD_OK)
            return FALSE;

        return TRUE;
    }

    

    int
    fmod_adjust_ghsound_general_volumes(float new_general_volume, float new_general_music_volume, float new_general_ambient_volume, float new_general_sfx_volume, float new_general_ui_volume)
    {
        general_volume = new_general_volume;
        general_music_volume = new_general_music_volume;
        general_ambient_volume = new_general_ambient_volume;
        general_sfx_volume = new_general_sfx_volume;
        general_ui_volume = new_general_ui_volume;

        FMOD_RESULT result;
        for (int i = 0; i <= 1; i++)
        {
            if (musicInstances[i].eventInstance)
            {
                enum ghsound_types soundid = musicInstances[i].ghsound;
                struct ghsound_eventmapping eventmap = ghsound2event[soundid];
                float event_volume = eventmap.volume;
                result = musicInstances[i].eventInstance->setVolume(min(1.0f, musicInstances[i].normalVolume * event_volume * general_music_volume * general_volume));
            }
        }
        for (int i = 0; i <= 1; i++)
        {
            if (levelAmbientInstances[i].eventInstance)
            {
                enum ghsound_types soundid = levelAmbientInstances[i].ghsound;
                struct ghsound_eventmapping eventmap = ghsound2event[soundid];
                float event_volume = eventmap.volume;
                result = levelAmbientInstances[i].eventInstance->setVolume(min(1.0f, levelAmbientInstances[i].normalVolume * event_volume * general_ambient_volume * general_volume));
            }
        }
        for (int i = 0; i <= 1; i++)
        {
            if (occupationAmbientInstances[i].eventInstance)
            {
                enum ghsound_types soundid = occupationAmbientInstances[i].ghsound;
                struct ghsound_eventmapping eventmap = ghsound2event[soundid];
                float event_volume = eventmap.volume;
                result = occupationAmbientInstances[i].eventInstance->setVolume(min(1.0f, occupationAmbientInstances[i].normalVolume * event_volume * general_ambient_volume * general_volume));
            }
        }
        for (int i = 0; i <= 1; i++)
        {
            if (effectAmbientInstances[i].eventInstance)
            {
                enum ghsound_types soundid = effectAmbientInstances[i].ghsound;
                struct ghsound_eventmapping eventmap = ghsound2event[soundid];
                float event_volume = eventmap.volume;
                result = effectAmbientInstances[i].eventInstance->setVolume(min(1.0f, effectAmbientInstances[i].normalVolume * event_volume * general_ambient_volume * general_volume));
            }
        }
        for (int i = 0; i < NUM_IMMEDIATE_SOUND_INSTANCES; i++)
        {
            if (immediateSoundInstances[i].eventInstance)
            {
                enum ghsound_types soundid = immediateSoundInstances[i].ghsound;
                struct ghsound_eventmapping eventmap = ghsound2event[soundid];
                float event_volume = eventmap.volume;
                float relevant_general_volume = (immediateSoundInstances[i].sound_type == IMMEDIATE_SOUND_UI ? general_ui_volume : general_sfx_volume);
                result = immediateSoundInstances[i].eventInstance->setVolume(min(1.0f, immediateSoundInstances[i].normalVolume * event_volume * relevant_general_volume * general_volume));
            }
        }
        for (GNHSoundInstance* curr = ambient_base; curr; curr = curr->next_instance)
        {
            if (curr->eventInstance)
            {
                enum ghsound_types soundid = curr->ghsound;
                struct ghsound_eventmapping eventmap = ghsound2event[soundid];
                float event_volume = eventmap.volume;
                result = curr->eventInstance->setVolume(min(1.0f, curr->normalVolume * event_volume * general_ambient_volume * general_volume));
            }
        }

        result = fmod_studio_system->update();
        if (result != FMOD_OK)
            return FALSE;

        return TRUE;
    }

    int
    fmod_add_ambient_ghsound(enum ghsound_types ghsound, float fmod_volume, void** ambient_sound_ptr_ptr)
    {
        FMOD_RESULT result;

        struct ghsound_eventmapping eventmap = ghsound2event[ghsound];
        float event_volume = eventmap.volume;
        if (!eventmap.eventPath || !strcmp(eventmap.eventPath, ""))
            return FALSE;

        Studio::EventDescription* ambientDescription = NULL;
        result = fmod_studio_system->getEvent(eventmap.eventPath, &ambientDescription);

        if (result != FMOD_OK)
            return FALSE;

        Studio::EventInstance* ambientInstance = NULL;
        result = ambientDescription->createInstance(&ambientInstance);
        if (result != FMOD_OK)
            return FALSE;

        /* Set volume */
        ambientInstance->setVolume(fmod_volume * event_volume * general_ambient_volume * general_volume);

        /* Create new GHSoundInstance */
        GNHSoundInstance* new_ghs_instance = (GNHSoundInstance*)malloc(sizeof(GNHSoundInstance));
        if (!new_ghs_instance)
        {
            result = ambientInstance->release();
            return FALSE;
        }

        /* Play sound */
        result = ambientInstance->start();
        if (result != FMOD_OK)
        {
            result = ambientInstance->release();
            free(new_ghs_instance);
            return FALSE;
        }

        memset((void*)new_ghs_instance, 0, sizeof(new_ghs_instance));
        new_ghs_instance->next_instance = ambient_base;
        ambient_base = new_ghs_instance;
        
        new_ghs_instance->eventInstance = ambientInstance;
        new_ghs_instance->ghsound = ghsound;
        new_ghs_instance->normalVolume = fmod_volume;

        result = fmod_studio_system->update();
        if (result != FMOD_OK)
            return FALSE;

        *ambient_sound_ptr_ptr = (void*)new_ghs_instance;

        return TRUE;
    }

    int
    fmod_delete_ambient_ghsound(void* ambient_sound_ptr)
    {
        if (!ambient_sound_ptr)
            return FALSE;

        FMOD_RESULT result;
        boolean found = FALSE;
        GNHSoundInstance* ghs_ptr = (GNHSoundInstance*)ambient_sound_ptr;
        for (GNHSoundInstance* ghs_curr = ambient_base; ghs_curr; ghs_curr = ghs_curr->next_instance)
        {
            if (ghs_curr == ghs_ptr)
            {
                found = TRUE;
                break;
            }
        }

        if (!found)
            return FALSE;

        if (!ghs_ptr->eventInstance)
            return FALSE;

        result = ghs_ptr->eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
        if (result != FMOD_OK)
            return FALSE;

        result = fmod_studio_system->update();
        if (result != FMOD_OK)
            return FALSE;

        result = ghs_ptr->eventInstance->release();
        if (result != FMOD_OK)
            return FALSE;

        GNHSoundInstance* prev = NULL;
        for (GNHSoundInstance* curr = ambient_base; curr; curr = curr->next_instance)
        {
            if (curr == ghs_ptr)
            {
                if (prev == NULL)
                    ambient_base = curr->next_instance;
                else
                    prev->next_instance = curr->next_instance;

                break;
            }
            prev = curr;
        }
        
        free(ghs_ptr);

        return TRUE;
    }

    int
    fmod_set_ambient_ghsound_volume(void* ambient_sound_ptr, float fmod_volume)
    {
        if (!ambient_sound_ptr)
            return FALSE;

        if (fmod_volume < 0.0f || fmod_volume > 1.0f)
            return FALSE;

        FMOD_RESULT result;
        GNHSoundInstance* ghs_ptr = (GNHSoundInstance*)ambient_sound_ptr;
        if (!ghs_ptr->eventInstance)
            return FALSE;

        float old_volume;
        result = ghs_ptr->eventInstance->getVolume(&old_volume);
        if (result != FMOD_OK)
            return FALSE;

        enum ghsound_types soundid = ghs_ptr->ghsound;
        struct ghsound_eventmapping eventmap = ghsound2event[soundid];
        float event_volume = eventmap.volume;
        result = ghs_ptr->eventInstance->setVolume(fmod_volume * event_volume * general_ambient_volume * general_volume);
        if (result != FMOD_OK)
            return FALSE;

        if (old_volume == 0.0f && fmod_volume > 0.0f)
            result = ghs_ptr->eventInstance->start();
        else if (old_volume > 0.0f && fmod_volume == 0.0f)
            result = ghs_ptr->eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);

        if (result != FMOD_OK)
            return FALSE;

        result = fmod_studio_system->update();
        if (result != FMOD_OK)
            return FALSE;

        ghs_ptr->normalVolume = fmod_volume;

        return TRUE;
    }


    boolean
    fmod_stop_all_sounds(struct stop_all_info info)
    {

        FMOD_RESULT result;
        if (info.stop_flags & 1)
        {
            for (int i = 0; i <= 1; i++)
            {
                if (musicInstances[i].eventInstance)
                {
                    if ((result = musicInstances[i].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT)) != FMOD_OK)
                        return FALSE;
                    if ((result = musicInstances[i].eventInstance->release()) != FMOD_OK)
                        return FALSE;
                    musicInstances[i].eventInstance = 0;
                }
            }
        }

        for (int i = 0; i <= 1; i++)
        {
            if (levelAmbientInstances[i].eventInstance)
            {
                if (levelAmbientInstances[i].normalVolume > 0.0f && (result = levelAmbientInstances[i].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT)) != FMOD_OK)
                    return FALSE;
                if ((result = levelAmbientInstances[i].eventInstance->release()) != FMOD_OK)
                    return FALSE;
                levelAmbientInstances[i].eventInstance = 0;
            }
        }
        for (int i = 0; i <= 1; i++)
        {
            if (occupationAmbientInstances[i].eventInstance)
            {
                if (occupationAmbientInstances[i].normalVolume > 0.0f && (result = occupationAmbientInstances[i].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT)) != FMOD_OK)
                    return FALSE;
                if ((result = occupationAmbientInstances[i].eventInstance->release()) != FMOD_OK)
                    return FALSE;
                occupationAmbientInstances[i].eventInstance = 0;
            }
        }
        for (int i = 0; i <= 1; i++)
        {
            if (effectAmbientInstances[i].eventInstance)
            {
                if (effectAmbientInstances[i].normalVolume > 0.0f && (result = effectAmbientInstances[i].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT)) != FMOD_OK)
                    return FALSE;
                if ((result = effectAmbientInstances[i].eventInstance->release()) != FMOD_OK)
                    return FALSE;
                effectAmbientInstances[i].eventInstance = 0;
            }
        }
        if (info.stop_flags & 2)
        {
            for (int i = 0; i < NUM_IMMEDIATE_SOUND_INSTANCES; i++)
            {
                if (immediateSoundInstances[i].eventInstance)
                {
                    if (immediateSoundInstances[i].normalVolume > 0.0f && (result = immediateSoundInstances[i].eventInstance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT)) != FMOD_OK)
                        return FALSE;
                    if ((result = immediateSoundInstances[i].eventInstance->release()) != FMOD_OK)
                        return FALSE;
                    immediateSoundInstances[i].eventInstance = 0;
                }
            }
        }

        /* These we just set volume to zero, since they are linked with sound_sources */
        for (GNHSoundInstance* curr = ambient_base; curr; curr = curr->next_instance)
        {
            if (curr->eventInstance)
            {
                if (curr->normalVolume > 0.0f)
                    fmod_set_ambient_ghsound_volume((void*)curr, 0.0f);
            }
        }

        result = fmod_studio_system->update();
        if (result != FMOD_OK)
            return FALSE;

        return TRUE;
    }

}


/* soundfx.cpp */
