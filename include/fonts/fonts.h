// TODO: header

#ifndef _PROS_FONTS
#define _PROS_FONTS

/**
 * Japanese Hiragana and Katakana (unicode 0x3040-0x309F and 0x30A0-0x30FF)
 *
 * Note: to use Japanese Hiragana, Katakana, and Kanji all together without
 * needing to switch fonts for Kanji, make sure to define the symbols for both
 * this font and the CJK font, and then call
 * lv_font_add(&pros_font_yu_gothic_ui_cjk, &pros_font_yu_gothic_ui)
 */
#ifdef USE_PROS_FONT_YU_GOTHIC_UI
LV_FONT_DECLARE(pros_font_yu_gothic_ui);
#endif

/**
 * CJK Unified Ideographs (unicode 0x4E00-0x62FF, 0x6300-0x77FF, 0x7800-0x8CFF,
 * and 0x8D00-0x9FFF)
 */
#ifdef USE_PROS_FONT_YU_GOTHIC_UI_CJK
LV_FONT_DECLARE(pros_font_yu_gothic_ui_cjk);
#endif

#endif
