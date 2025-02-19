/* GnollHack File Change Notice: This file has been changed from the original. Date of last change: 2023-03-17 */

/* GnollHack 4.0    mhfont.c    $NHDT-Date: 1432512812 2015/05/25 00:13:32 $  $NHDT-Branch: master $:$NHDT-Revision: 1.23 $ */
/* Copyright (C) 2001 by Alex Kompel      */
/* GnollHack may be freely redistributed.  See license for details. */

/* font management and such */

#include "win10.h"
#include "winos.h"
#include "mhfont.h"
#include "resource.h"

/* font table - 64 fonts ought to be enough */
#define MAXFONTS 64

static cached_font font_table[MAXFONTS];
static int font_table_size = 0;

#define NHFONT_CODE(win, attr) (((attr & 0xFF) << 8) | (win_type & 0xFF))

static void __cdecl font_table_cleanup(void);

HFONT
mswin_create_splashfont(HWND hWnd)
{
    HDC hdc = GetDC(hWnd);
    double scale = win10_monitor_scale(hWnd);
    LOGFONT lgfnt;
    ZeroMemory(&lgfnt, sizeof(lgfnt));
    lgfnt.lfHeight = -(int)(80 * scale);       // height of font
    lgfnt.lfWidth = 0;                         // average character width
    lgfnt.lfEscapement = 0;                    // angle of escapement
    lgfnt.lfOrientation = 0;                   // base-line orientation angle
    lgfnt.lfWeight = FW_BOLD;                  // font weight
    lgfnt.lfItalic = FALSE;                    // italic attribute option
    lgfnt.lfUnderline = FALSE;                 // underline attribute option
    lgfnt.lfStrikeOut = FALSE;                 // strikeout attribute option
    lgfnt.lfCharSet = ANSI_CHARSET;            // character set identifier
    lgfnt.lfOutPrecision = OUT_DEFAULT_PRECIS; // output precision
    lgfnt.lfClipPrecision = CLIP_DEFAULT_PRECIS; // clipping precision
    lgfnt.lfQuality = DEFAULT_QUALITY;           // output quality
    lgfnt.lfPitchAndFamily = DEFAULT_PITCH;      // pitch and family
    NH_A2W("Underwood Champion", lgfnt.lfFaceName, LF_FACESIZE);
    HFONT font = CreateFontIndirect(&lgfnt);
    ReleaseDC(hWnd, hdc);

    return font;
}

BOOL 
mswin_font_supports_unicode(HFONT hFont)
{
    for (int i = 0; i < font_table_size; i++)
        if (font_table[i].hFont == hFont)
            return font_table[i].supportsUnicode;

    return FALSE;
}

/* create font based on window type, charater attributes and
   window device context */
cached_font *
mswin_get_font(int win_type, int attr, HDC hdc, BOOL replace)
{
    HFONT fnt = NULL;
    LOGFONT lgfnt;
    int font_size = 14;
    char* font_name = "Consolas";
    int font_index;
    static BOOL once = FALSE;

    attr = attr & ATR_ATTR_MASK;

    if (!once) {
        once = TRUE;
        atexit(font_table_cleanup);
    }

    ZeroMemory(&lgfnt, sizeof(lgfnt));

    /* try find font in the table */
    for (font_index = 0; font_index < font_table_size; font_index++)
        if (NHFONT_CODE(win_type, attr) == font_table[font_index].code)
            break;

    if (!replace && font_index < font_table_size)
        return &font_table[font_index];

    switch (win_type) {
    case NHW_STATUS:
        font_size = (attr == ATR_BOLD) ? iflags.wc_fontsiz_status + 1
                                       : iflags.wc_fontsiz_status;
        lgfnt.lfHeight = -font_size * GetDeviceCaps(hdc, LOGPIXELSY)
                         / 72;   // height of font
        lgfnt.lfWidth = 0;       // average character width
        lgfnt.lfEscapement = 0;  // angle of escapement
        lgfnt.lfOrientation = 0; // base-line orientation angle
        lgfnt.lfWeight =
            (attr == ATR_BOLD) ? FW_BOLD : FW_NORMAL; // font weight
        lgfnt.lfItalic = FALSE;            // italic attribute option
        lgfnt.lfUnderline = (attr == ATR_ULINE); // underline attribute option
        lgfnt.lfStrikeOut = FALSE;         // strikeout attribute option
        lgfnt.lfCharSet = mswin_charset(); // character set identifier
        lgfnt.lfOutPrecision = OUT_DEFAULT_PRECIS;   // output precision
        lgfnt.lfClipPrecision = CLIP_DEFAULT_PRECIS; // clipping precision
        lgfnt.lfQuality = DEFAULT_QUALITY;           // output quality
        if (iflags.wc_font_status && *iflags.wc_font_status) {
            font_name = iflags.wc_font_status;
            lgfnt.lfPitchAndFamily = DEFAULT_PITCH; // pitch and family
            NH_A2W(iflags.wc_font_status, lgfnt.lfFaceName, LF_FACESIZE);
        } else {
            lgfnt.lfPitchAndFamily = FIXED_PITCH; // pitch and family
        }
        break;

    case NHW_MENU:
        font_size = iflags.wc_fontsiz_menu;
        lgfnt.lfHeight = -font_size * GetDeviceCaps(hdc, LOGPIXELSY) / 72;   // height of font
        lgfnt.lfWidth = 0;       // average character width
        lgfnt.lfEscapement = 0;  // angle of escapement
        lgfnt.lfOrientation = 0; // base-line orientation angle
        lgfnt.lfWeight = (attr == ATR_BOLD || attr == ATR_INVERSE)
                             ? FW_BOLD
                             : FW_NORMAL; // font weight
        lgfnt.lfItalic =
            (attr == ATR_BLINK) ? TRUE : FALSE; // italic attribute option
        lgfnt.lfUnderline =
            (attr == ATR_ULINE) ? TRUE : FALSE; // underline attribute option
        lgfnt.lfStrikeOut = FALSE;              // strikeout attribute option
        lgfnt.lfCharSet = mswin_charset();      // character set identifier
        lgfnt.lfOutPrecision = OUT_DEFAULT_PRECIS;   // output precision
        lgfnt.lfClipPrecision = CLIP_DEFAULT_PRECIS; // clipping precision
        lgfnt.lfQuality = DEFAULT_QUALITY;           // output quality
        if (iflags.wc_font_menu && *iflags.wc_font_menu) {
            font_name = iflags.wc_font_menu;
            lgfnt.lfPitchAndFamily = DEFAULT_PITCH; // pitch and family
            NH_A2W(iflags.wc_font_menu, lgfnt.lfFaceName, LF_FACESIZE);
        } else {
            lgfnt.lfPitchAndFamily = FIXED_PITCH; // pitch and family
        }
        break;

    case NHW_MESSAGE:
        font_size = (attr == ATR_INVERSE) ? iflags.wc_fontsiz_message + 1
                                          : iflags.wc_fontsiz_message;
        lgfnt.lfHeight = -font_size * GetDeviceCaps(hdc, LOGPIXELSY)
                         / 72;   // height of font
        lgfnt.lfWidth = 0;       // average character width
        lgfnt.lfEscapement = 0;  // angle of escapement
        lgfnt.lfOrientation = 0; // base-line orientation angle
        lgfnt.lfWeight = (attr == ATR_BOLD || attr == ATR_INVERSE)
                             ? FW_BOLD
                             : FW_NORMAL; // font weight
        lgfnt.lfItalic =
            (attr == ATR_BLINK) ? TRUE : FALSE; // italic attribute option
        lgfnt.lfUnderline =
            (attr == ATR_ULINE) ? TRUE : FALSE; // underline attribute option
        lgfnt.lfStrikeOut = FALSE;              // strikeout attribute option
        lgfnt.lfCharSet = mswin_charset();      // character set identifier
        lgfnt.lfOutPrecision = OUT_DEFAULT_PRECIS;   // output precision
        lgfnt.lfClipPrecision = CLIP_DEFAULT_PRECIS; // clipping precision
        lgfnt.lfQuality = DEFAULT_QUALITY;           // output quality
        if (iflags.wc_font_message && *iflags.wc_font_message) {
            font_name = iflags.wc_font_message;
            lgfnt.lfPitchAndFamily = DEFAULT_PITCH; // pitch and family
            NH_A2W(iflags.wc_font_message, lgfnt.lfFaceName, LF_FACESIZE);
        } else {
            lgfnt.lfPitchAndFamily = VARIABLE_PITCH; // pitch and family
        }
        break;

    case NHW_TEXT:
        font_size = iflags.wc_fontsiz_menu;
        lgfnt.lfHeight = -font_size * GetDeviceCaps(hdc, LOGPIXELSY) / 72;   // height of font
        lgfnt.lfWidth = 0;       // average character width
        lgfnt.lfEscapement = 0;  // angle of escapement
        lgfnt.lfOrientation = 0; // base-line orientation angle
        lgfnt.lfWeight = (attr == ATR_BOLD || attr == ATR_INVERSE)
                             ? FW_BOLD
                             : FW_NORMAL; // font weight
        lgfnt.lfItalic =
            (attr == ATR_BLINK) ? TRUE : FALSE; // italic attribute option
        lgfnt.lfUnderline =
            (attr == ATR_ULINE) ? TRUE : FALSE; // underline attribute option
        lgfnt.lfStrikeOut = FALSE;              // strikeout attribute option
        lgfnt.lfCharSet = mswin_charset();      // character set identifier
        lgfnt.lfOutPrecision = OUT_DEFAULT_PRECIS;   // output precision
        lgfnt.lfClipPrecision = CLIP_DEFAULT_PRECIS; // clipping precision
        lgfnt.lfQuality = DEFAULT_QUALITY;           // output quality
        if (iflags.wc_font_text && *iflags.wc_font_text) {
            font_name = iflags.wc_font_text;
            lgfnt.lfPitchAndFamily = DEFAULT_PITCH; // pitch and family
            NH_A2W(iflags.wc_font_text, lgfnt.lfFaceName, LF_FACESIZE);
        } else {
            lgfnt.lfPitchAndFamily = FIXED_PITCH; // pitch and family
        }
        break;
    }


    /* Create font */
    fnt = CreateFontIndirect(&lgfnt);

    /* add font to the table */
    if (font_index == font_table_size) {
        if (font_table_size >= MAXFONTS)
        {
            panic("font table overflow!");
            return (cached_font*)0;
        }
        font_table_size++;
    } else {
        DeleteObject(font_table[font_index].hFont);
    }

    font_table[font_index].code = NHFONT_CODE(win_type, attr);
    font_table[font_index].hFont = fnt;
    font_table[font_index].supportsUnicode = winos_font_support_cp437(fnt);
    font_table[font_index].size = (float)font_size;
    strcpy(font_table[font_index].font_name, font_name);
    font_table[font_index].font_attributes = attr;

    HGDIOBJ savedFont = SelectObject(hdc, fnt);
    SIZE size;
    GetTextExtentPoint32A(hdc, " ", 1, &size);
    SelectObject(hdc, savedFont);

    font_table[font_index].height = size.cy;
    font_table[font_index].width = size.cx;

    return &font_table[font_index];
}

UINT
mswin_charset()
{
    CHARSETINFO cis;
    /* if (SYMHANDLING(H_IBM))
        if (TranslateCharsetInfo((DWORD *) (uintptr_t) GetOEMCP(), &cis, TCI_SRCCODEPAGE))
            return cis.ciCharset;
        else
            return OEM_CHARSET;
    else */ if (TranslateCharsetInfo((DWORD *) (uintptr_t) GetACP(), &cis, TCI_SRCCODEPAGE))
        return cis.ciCharset;
    else
        return ANSI_CHARSET;
}

void __cdecl font_table_cleanup(void)
{
    int i;
    for (i = 0; i < font_table_size; i++) {
        DeleteObject(font_table[i].hFont);
    }
    font_table_size = 0;
}

void
init_resource_fonts()
{
    /* Install font from resource */
    HINSTANCE hResInstance = (HINSTANCE)GetModuleHandle(NULL);
    HRSRC res = FindResource(hResInstance, MAKEINTRESOURCE(IDR_RCDATA_FONT), RT_RCDATA);

    if (res)
    {
        HGLOBAL mem = LoadResource(hResInstance, res);
        if (!mem)
            return;
        void* data = LockResource(mem);
        size_t len = SizeofResource(hResInstance, res);

        DWORD nFonts;
        HANDLE m_fonthandle = AddFontMemResourceEx(
            data,       // font resource
            len,       // number of bytes in font resource 
            NULL,          // Reserved. Must be 0.
            &nFonts      // number of fonts installed
        );

        nFonts = nFonts;
        AddFontToGdiPlus(data, len);
    }

}
