// dllmain.c : Defines the entry point for the DLL application.

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include "dllhack.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


extern struct callback_procs dll_callbacks;
extern void FDECL(set_dll_wincaps, (unsigned long, unsigned long));
extern int NDECL(GnollHackStart);

DLL int WINAPI RunGnollHack(
    unsigned long wincap1,
    unsigned long wincap2,
    InitWindowsCallback callback_init_nhwindows,
    PlayerSelectionCallback callback_player_selection,
    AskNameCallback callback_askname,
    GetEventCallback callback_get_nh_event,
    ExitWindowsCallback callback_exit_nhwindows,
    SuspendWindowsCallback callback_suspend_nhwindows,
    ResumeWindowsCallback callback_resume_nhwindows,
    CreateWindowCallback callback_create_nhwindow,
    ClearWindowCallback callback_clear_nhwindow,
    DisplayWindowCallback callback_display_nhwindow,
    DestroyWindowCallback callback_destroy_nhwindow,
    CursCallback callback_curs,
    PutStrExCallback callback_putstr_ex,
    PutMixedCallback callback_putmixed,
    DisplayFileCallback callback_display_file,
    StartMenuCallback callback_start_menu,
    AddMenuCallback callback_add_menu,
    AddExtendedMenuCallback callback_add_extended_menu,
    EndMenuCallback callback_end_menu,
    SelectMenuCallback callback_select_menu,
    MessageMenuCallback callback_message_menu, /* no need for X-specific handling */
    UpdateInventoryCallback callback_update_inventory,
    MarkSynchCallback callback_mark_synch,
    WaitSynchCallback callback_wait_synch,
    /* If clipping is on */
    ClipAroundCallback callback_cliparound,
    /* If positionbar is on */
    UpdatePositionBarCallback callback_update_positionbar,
    PrintGlyphCallback callback_print_glyph,
    RawPrintCallback callback_raw_print,
    RawPrintBoldCallback callback_raw_print_bold,
    GetChCallback callback_nhgetch,
    PosKeyCallback callback_nh_poskey,
    BellCallback callback_nhbell,
    DoPrevMessageCallback callback_doprev_message,
    YnFunctionCallback callback_yn_function,
    GetLinCallback callback_getlin,
    GetExtCmdCallback callback_get_ext_cmd,
    NumberPadCallback callback_number_pad,
    DelayOutputCallback callback_delay_output,
    DelayOutputMillisecondsCallback callback_delay_output_milliseconds,
    DelayOutputIntervalsCallback callback_delay_output_intervals,

    /* Mac */
    ChangeColorCallback callback_change_color,
    ChangeBackgroundCallback callback_change_background,
    SetFontNameCallback callback_set_font_name,
    GetColorStringCallback callback_get_color_string,

    /* other defs that really should go away (they're tty specific) */
    StartScreenCallback callback_start_screen,
    EndScreenCallback callback_end_screen,
    OutRipCallback callback_outrip,
    PreferenceUpdateCallback callback_preference_update,
    GetMsgHistoryCallback callback_getmsghistory,
    PutMsgHistoryCallback callback_putmsghistory,
    StatusInitCallback callback_status_init,
    StatusFinishCallback callback_status_finish,
    StatusEnableFieldCallback callback_status_enablefield,
    StatusUpdateCallback callback_status_update,
    CanSuspendYesCallback callback_can_suspend_yes,
    StretchWindowCallback callback_stretch_window,
    SetAnimationTimerCallback callback_set_animation_timer,
    OpenSpecialViewCallback callback_open_special_view,
    StopAllSoundsCallback callback_stop_all_sounds,
    PlayImmediateSoundCallback callback_play_immediate_ghsound,
    PlayOccupationAmbientCallback callback_play_ghsound_occupation_ambient,
    PlayEffectAmbientCallback callback_play_ghsound_effect_ambient,
    SetEffectAmbientVolumeCallback callback_set_effect_ambient_volume,
    PlayMusicCallback callback_play_ghsound_music,
    PlayLevelAmbientCallback callback_play_ghsound_level_ambient,
    PlayEnvironmentAmbientCallback callback_play_ghsound_environment_ambient,
    AdjustGeneralVolumesCallback callback_adjust_ghsound_general_volumes,
    AddAmbientSoundCallback callback_add_ambient_ghsound,
    DeleteAmbientSoundCallback callback_delete_ambient_ghsound,
    SetAmbientVolumeCallback callback_set_ambient_ghsound_volume,
    ExitHackCallback callback_exit_hack,

    GetCwdCallback callback_getcwd,
    MessageBoxCallback callback_messagebox,
    OutRipBeginCallback callback_outrip_begin,
    OutRipEndCallback callback_outrip_end
)
{
    /* Set wincaps */
    set_dll_wincaps(wincap1, wincap2);

    /* Set callback function pointers here */
    dll_callbacks.callback_init_nhwindows = callback_init_nhwindows;
    dll_callbacks.callback_player_selection = callback_player_selection;
    dll_callbacks.callback_askname = callback_askname;
    dll_callbacks.callback_get_nh_event = callback_get_nh_event;
    dll_callbacks.callback_exit_nhwindows = callback_exit_nhwindows;
    dll_callbacks.callback_suspend_nhwindows = callback_suspend_nhwindows;
    dll_callbacks.callback_resume_nhwindows = callback_resume_nhwindows;
    dll_callbacks.callback_create_nhwindow = callback_create_nhwindow;
    dll_callbacks.callback_display_nhwindow = callback_display_nhwindow;
    dll_callbacks.callback_display_file = callback_display_file;
    dll_callbacks.callback_curs = callback_curs;
    dll_callbacks.callback_putstr_ex = callback_putstr_ex;
    dll_callbacks.callback_putmixed = callback_putmixed;
    dll_callbacks.callback_display_file = callback_display_file;
    dll_callbacks.callback_start_menu = callback_start_menu;
    dll_callbacks.callback_add_menu = callback_add_menu;
    dll_callbacks.callback_add_extended_menu = callback_add_extended_menu;
    dll_callbacks.callback_end_menu = callback_end_menu;
    dll_callbacks.callback_select_menu = callback_select_menu;
    dll_callbacks.callback_message_menu = callback_message_menu;
    dll_callbacks.callback_update_inventory = callback_update_inventory;
    dll_callbacks.callback_mark_synch = callback_mark_synch;
    dll_callbacks.callback_wait_synch = callback_wait_synch;
    dll_callbacks.callback_cliparound = callback_cliparound;
    dll_callbacks.callback_update_positionbar = callback_update_positionbar;
    dll_callbacks.callback_print_glyph = callback_print_glyph;
    dll_callbacks.callback_raw_print = callback_raw_print;
    dll_callbacks.callback_raw_print_bold = callback_raw_print_bold;
    dll_callbacks.callback_nhgetch = callback_nhgetch;
    dll_callbacks.callback_nh_poskey = callback_nh_poskey;
    dll_callbacks.callback_nhbell = callback_nhbell;
    dll_callbacks.callback_nhbell = callback_nhbell;
    dll_callbacks.callback_doprev_message = callback_doprev_message;
    dll_callbacks.callback_yn_function = callback_yn_function;
    dll_callbacks.callback_getlin = callback_getlin;
    dll_callbacks.callback_yn_function = callback_yn_function;
    dll_callbacks.callback_get_ext_cmd = callback_get_ext_cmd;
    dll_callbacks.callback_number_pad = callback_number_pad;
    dll_callbacks.callback_delay_output = callback_delay_output;
    dll_callbacks.callback_delay_output_milliseconds = callback_delay_output_milliseconds;
    dll_callbacks.callback_delay_output_intervals = callback_delay_output_intervals;
    dll_callbacks.callback_change_color = callback_change_color;
    dll_callbacks.callback_change_background = callback_change_background;
    dll_callbacks.callback_set_font_name = callback_set_font_name;
    dll_callbacks.callback_get_color_string = callback_get_color_string;
    dll_callbacks.callback_start_screen = callback_start_screen;
    dll_callbacks.callback_end_screen = callback_end_screen;
    dll_callbacks.callback_outrip = callback_outrip;
    dll_callbacks.callback_preference_update = callback_preference_update;
    dll_callbacks.callback_getmsghistory = callback_getmsghistory;
    dll_callbacks.callback_putmsghistory = callback_putmsghistory;
    dll_callbacks.callback_status_init = callback_status_init;
    dll_callbacks.callback_status_finish = callback_status_finish;
    dll_callbacks.callback_status_enablefield = callback_status_enablefield;
    dll_callbacks.callback_status_update = callback_status_update;
    dll_callbacks.callback_can_suspend_yes = callback_can_suspend_yes;
    dll_callbacks.callback_stretch_window = callback_stretch_window;
    dll_callbacks.callback_set_animation_timer = callback_set_animation_timer;
    dll_callbacks.callback_open_special_view = callback_open_special_view;
    dll_callbacks.callback_stop_all_sounds = callback_stop_all_sounds;
    dll_callbacks.callback_play_immediate_ghsound = callback_play_immediate_ghsound;
    dll_callbacks.callback_play_ghsound_occupation_ambient = callback_play_ghsound_occupation_ambient;
    dll_callbacks.callback_play_ghsound_effect_ambient = callback_play_ghsound_effect_ambient;
    dll_callbacks.callback_set_effect_ambient_volume = callback_set_effect_ambient_volume;
    dll_callbacks.callback_play_ghsound_music = callback_play_ghsound_music;
    dll_callbacks.callback_play_ghsound_level_ambient = callback_play_ghsound_level_ambient;
    dll_callbacks.callback_play_ghsound_environment_ambient = callback_play_ghsound_environment_ambient;
    dll_callbacks.callback_adjust_ghsound_general_volumes = callback_adjust_ghsound_general_volumes;
    dll_callbacks.callback_add_ambient_ghsound = callback_add_ambient_ghsound;
    dll_callbacks.callback_delete_ambient_ghsound = callback_delete_ambient_ghsound;
    dll_callbacks.callback_set_ambient_ghsound_volume = callback_set_ambient_ghsound_volume;
    dll_callbacks.callback_exit_hack = callback_exit_hack;
    dll_callbacks.callback_getcwd = callback_getcwd;
    dll_callbacks.callback_messagebox = callback_messagebox;
    dll_callbacks.callback_outrip_begin = callback_outrip_begin;
    dll_callbacks.callback_outrip_end = callback_outrip_end;

    /* Start GnollHack by calling main */
    return GnollHackStart();
}

DLL int WINAPI RunGnollHackSimple(
    unsigned long wincap1,
    unsigned long wincap2)
{
    /* Set wincaps */
    set_dll_wincaps(wincap1, wincap2);

    return GnollHackStart();
}

