// TODO: header

#ifndef _PROS_FONTS
#define _PROS_FONTS

/**
 * Japanese Hiragana and Katakana (unicode 0x3040-0x309F and 0x30A0-0x30FF)
 */
#ifdef USE_PROS_FONT_YU_GOTHIC_UI
LV_FONT_DECLARE(pros_font_yu_gothic_ui);
#endif

/**
 * CJK Unified Ideographs, Part 1 of 4 (unicode 0x4E00-0x62FF)
 */
#ifdef USE_PROS_FONT_YU_GOTHIC_UI_CJK1
LV_FONT_DECLARE(pros_font_yu_gothic_ui_cjk1);
#endif

/**
 * CJK Unified Ideographs, Part 2 of 4 (unicode 0x6300-0x77FF)
 */
#ifdef USE_PROS_FONT_YU_GOTHIC_UI_CJK2
LV_FONT_DECLARE(pros_font_yu_gothic_ui_cjk2);
#endif

/**
 * CJK Unified Ideographs, Part 3 of 4 (unicode 0x7800-0x8CFF)
 */
#ifdef USE_PROS_FONT_YU_GOTHIC_UI_CJK3
LV_FONT_DECLARE(pros_font_yu_gothic_ui_cjk3);
#endif

/**
 * CJK Unified Ideographs, Part 4 of 4 (unicode 0x8D00-0x9FFF)
 */
#ifdef USE_PROS_FONT_YU_GOTHIC_UI_CJK4
LV_FONT_DECLARE(pros_font_yu_gothic_ui_cjk4);
#endif

#endif
