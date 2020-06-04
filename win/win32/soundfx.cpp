/*
 * soundfx.cpp
 * GnollHack Sound Effects
 *
 * Copyright (c) Janne Gustafsson, 2020
 *
 */

#include <windows.h>
#include "fmod_studio.hpp"
#include "fmod.hpp"
#include "resource.h"

using namespace FMOD;
static System* fmod_system = (System*)0;
static Sound* sound1 = (Sound*)0;
static Sound* sound2 = (Sound*)0;
static Sound* sound3 = (Sound*)0;

extern "C" 
{
    boolean
    initialize_fmod()
    {
        FMOD_RESULT result;
        unsigned int version;
        void* extradriverdata = 0;

        result = System_Create(&fmod_system);
        result = fmod_system->getVersion(&version);

        if (version < FMOD_VERSION)
        {
//            Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
            return FALSE;
        }

        result = fmod_system->init(32, FMOD_INIT_NORMAL, extradriverdata);
        return TRUE;
    }

    void
    fmod_play_sound_example()
    {
        if (!fmod_system)
            return;

        Channel* channel = 0;
        FMOD_RESULT       result;

        //result = fmod_system->createSound("C:\\Users\\janne\\Test\\Sound Test\\Tower-Defense.wav", FMOD_DEFAULT, 0, &sound2);
        //result = sound2->setMode(FMOD_LOOP_NORMAL);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
        //result = fmod_system->playSound(sound2, 0, false, &channel);

        Sleep(500);

        result = fmod_system->createSound("C:\\Users\\janne\\Test\\Sound Test\\PowerUp20.wav", FMOD_DEFAULT, 0, &sound1);
        result = sound1->setMode(FMOD_LOOP_OFF);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
        result = fmod_system->playSound(sound1, 0, false, &channel);

        Sleep(500);

        /* Install font from resource */
        HINSTANCE hResInstance = (HINSTANCE)GetModuleHandle(NULL);
        HRSRC res = FindResource(hResInstance, MAKEINTRESOURCE(IDR_RCDATA_OGG), RT_RCDATA);

        if (res)
        {
            HGLOBAL mem = LoadResource(hResInstance, res);
            void* data = LockResource(mem);
            size_t len = SizeofResource(hResInstance, res);

            FMOD_CREATESOUNDEXINFO exinfo;
            memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
            exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
            exinfo.length = (unsigned int)len;

            result = fmod_system->createSound((const char*)data, FMOD_OPENMEMORY, &exinfo, &sound3);
            result = sound3->setMode(FMOD_LOOP_OFF);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
            result = fmod_system->playSound(sound3, 0, false, &channel);
        }
    }

    void
    fmod_stop_all_sounds()
    {
        FMOD_RESULT result;
        if (sound1)
        {
            result = sound1->release();
            sound1 = (Sound*)0;
        }
        if (sound2)
        {
            result = sound2->release();
            sound2 = (Sound*)0;
        }
        if (sound3)
        {
            result = sound3->release();
            sound3 = (Sound*)0;
        }
    }

}

/* soundfx.cpp */
