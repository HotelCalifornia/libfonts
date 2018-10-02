# libfonts

Extra fonts to use with PROS 3 and LVGL

## How to use

The first step is to download the template and install it:
1. Download the latest libfonts@{version}.zip from the releases page
2. Run `prosv5 c f path/to/downloaded/libfonts@{version}.zip`

Now you can add the library to your project:
1. `prosv5 c f libfonts`
2. `cd path/to/myproject`
3. `prosv5 c a libfonts`

Then, add the following to main.h:

```c
// use Yu Gothic UI font
#define USE_PROS_FONT_YU_GOTHIC_UI
#include "fonts/fonts.h"
```

Make sure that you define symbols for the fonts you need _before_ including the fonts.h file. The symbols are detailed below.

Now that you've enabled and included fonts of your choice, you can use them as you would normally use a font in LVGL. For more information about that, see the LVGL documentation about [fonts](https://littlevgl.com/basics#fonts) and [styles](https://littlevgl.com/basics#styles).

However, some of the fonts included in this library are unicode extensions, like Yu Gothic UI (provides Japanese Katakana and Hiragana) and Yu Gothic UI CJK (provides Kangxi/Kanji/Hanja characters). This means usually that they only contain the characters specified and nothing else, like punctuation. In order to make using fonts and extensions more seamless (than having to keep switching between them), LVGL provides the function `lv_font_add`, which can be used as in the following example:

```c
// add Japanese Hiragana and Katakana to the base font
lv_font_add(&pros_font_dejavu_mono20, &pros_font_yu_gothic_ui);

// add CJK characters to the base font
lv_font_add(&pros_font_dejavu_mono20, &pros_font_yu_gothic_ui_cjk1);
lv_font_add(&pros_font_dejavu_mono20, &pros_font_yu_gothic_ui_cjk2);
lv_font_add(&pros_font_dejavu_mono20, &pros_font_yu_gothic_ui_cjk3);
lv_font_add(&pros_font_dejavu_mono20, &pros_font_yu_gothic_ui_cjk4);
```

## List of fonts

| Font                | Description                                                                                        | Symbol                            | Variable                       |
|---------------------|----------------------------------------------------------------------------------------------------|-----------------------------------|--------------------------------|
| Yu Gothic UI        | Provides Japanese Katakana and Hiragana symbols. Unicode 0x3040-0x309F and 0x30A0-0x30FF           | `USE_PROS_FONT_YU_GOTHIC_UI`      | `&pros_font_yu_gothic_ui`      |
| Yu Gothic UI (CJK1) | Provides CJK Unified Ideographs (Kangxi/Kanji/Hanja characters) Part 1 of 4. Unicode 0x4E00-0x62FF | `USE_PROS_FONT_YU_GOTHIC_UI_CJK1` | `&pros_font_yu_gothic_ui_cjk1` |
| Yu Gothic UI (CJK2) | Provides CJK Unified Ideographs (Kangxi/Kanji/Hanja characters) Part 2 of 4. Unicode 0x6300-0x77FF | `USE_PROS_FONT_YU_GOTHIC_UI_CJK2` | `&pros_font_yu_gothic_ui_cjk2` |
| Yu Gothic UI (CJK3) | Provides CJK Unified Ideographs (Kangxi/Kanji/Hanja characters) Part 3 of 4. Unicode 0x7800-0x8CFF | `USE_PROS_FONT_YU_GOTHIC_UI_CJK3` | `&pros_font_yu_gothic_ui_cjk3` |
| Yu Gothic UI (CJK4) | Provides CJK Unified Ideographs (Kangxi/Kanji/Hanja characters) Part 4 of 4. Unicode 0x8D00-0x9FFF | `USE_PROS_FONT_YU_GOTHIC_UI_CJK4` | `&pros_font_yu_gothic_ui_cjk4` |

## Adding more fonts

If you'd like to see a font added to this library, open an issue or a pull request.

### Pull request

When making a PR, you need to do two things:

1. Add the converted font file to src/fonts. You can use the [tool on LVGL's site](https://littlevgl.com/ttf-font-to-c-array) to convert a TTF file. This should be exported with a height of 20px and a BPP of 4.
2. Edit include/fonts/fonts.h to include the declaration of your font

## FAQ*

#### Q: Are all the fonts going to be for language support?
A: In theory no. If you want a font like Comic Sans MS and provide just the Latin character set, that's fine too.

#### Q: Why are the CJK characters split into 4 parts?
A: There are a couple reasons. First, there are about 30,000 characters defined in the CJK Unicode block (which, incidentally, is also split into four parts). Following on from that, it turns out that exporting fonts at 1 BPP made them not so readable on the v5 screen, so I had to go back and re-export them at 4 BPP. Having a single file with 30,000 characters, each represented as a C array where 4 bits make up one pixel would have led to an almost unmaintainably massive file. So I decided to split them up the same way as Unicode does.

*yes, I did just make these questions up so the "frequently" part is a little bit of a lie
