/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** my_macros.h
*/

#ifndef MY_MACROS_H_
    #define MY_MACROS_H_

    #define MIN(x, y)           ((x) < (y) ? (x) : (y))
    #define MAX(x, y)           ((x) > (y) ? (x) : (y))

    #define RENDER_DISTANCE     15

    #define BACKGROUND          "./assets/backgrounds/"
    #define BUTTONS             "./assets/buttons/main_menu/"
    #define MENU_SETTINGS       "./assets/buttons/main_menu/settings/"
    #define FONTS               "./assets/fonts/"
    #define IMAGES              "./assets/images/"
    #define TITLES              "./assets/titles/"
    #define SETTINGS            "./assets/buttons/main_menu/settings/"
    #define STATS               BUTTONS "../character_stats/"

    #define STAT_DEFAULT        STATS "try-hard.png"
    #define STAT_STRENGTH       STATS "strenght.png"
    #define STAT_DEXTERITY      STATS "dext.png"

    #define OVERLAY             "./assets/overlay/"

    /* escape menu */
    #define ESCAPE_MENU         OVERLAY "./in_game_menu.png"

    /* Game State*/
    #define DEFAULT_GAME_STATE  0

    /* Icon */
    #define ICON                "./assets/images/icon.png"

    /* Credits */
    #define CREDITS             BACKGROUND "credits.png"

    /* Time */
    #define TIME_DIVIDER        1000000.0
    #define ANIMATION_TICK      0.15

    /* Key Code*/
    #define ESCAPE              36

    /* Splash Screen */
    #define RUINED_BACK         IMAGES "ruined_back.png"
    #define RUINED_FORE         IMAGES "ruined_fore.png"
    #define TITLE               IMAGES "title.png"
    #define SKIP                IMAGES "skip.png"
    #define RUINED_CITY         IMAGES "ruined_city.png"

    #define PLAY                BUTTONS "play.png"
    #define RESUME              BUTTONS "resume.png"
    #define SETTING             BUTTONS "settings.png"
    #define QUIT                BUTTONS "quit.png"

    /* Settings */
    #define LOW_RESOLUTION      SETTINGS "800x600.png"
    #define HIGH_RESOLUTION     SETTINGS "1920x1080.png"
    #define FULLSCREEN          SETTINGS "fullscreen.png"
    #define MINUS               SETTINGS "minus.png"
    #define MUSIC               SETTINGS "music.png"
    #define PLUS                SETTINGS "plus.png"
    #define SOUND               SETTINGS "sound.png"
    #define WINDOWED            SETTINGS "windowed.png"
    #define BORDERLESS          SETTINGS "borderless.png"
    #define SETTINGS_BACKGROUND BACKGROUND "settings_background.png"
    #define RESOLUTION_TITLE    TITLES "resolution_title.png"
    #define SOUNDS_TITLE        TITLES "sounds_title.png"

    /* Fonts */
    #define FFFFORWA            FONTS "FFFFORWA.TTF"

    /* Main Menu */
    #define RUINED_FORE_WIDTH   2880
    #define RUINED_BACK_WIDTH   2880
    #define SKIP_WIDTH          200
    #define MAIN_MENU           BUTTONS "main_menu.png"
    #define FADE_ITERATION      50

    /* FPS Counter*/
    #define SHOW_FPS_DEFAULT    1

    /* Sounds */
    #define INTRO_MUSIC         MUSICS "intro.ogg"
    #define SOUND_MANIFEST      "./assets/sounds/manifest"

    /* Backgrounds */
    #define NIGHT_SKY           BACKGROUND "night_sky.png"

    /* Cinematic */
    #define CINEMATIC           "./assets/cinematic/"
    #define TUTORIAL_DOOR       CINEMATIC "door_tutorial.png"
    #define TUTORIAL_FRAME      9
    #define DEATH_SCREEN        CINEMATIC "death_screen.png"
    #define DEATH_FRAME         17
    #define SPINNING_CAT        CINEMATIC "spinning_cat"
    #define CAT_FRAME           4
    #define PORTAL_TP           CINEMATIC "portal.png"
    #define PORTAL_FRAME        9

    /* Cursor */
    #define CURSOR              "./assets/cursor.png"
    #define CURSOR_OFFSET_X     0
    #define CURSOR_OFFSET_Y     0

    /* Particle Engine */
    #define PARTICLE            "./assets/particles/"
    #define FIRE                PARTICLE "fire_sheet.png"
    #define SMOKE               PARTICLE "smoke_sheet.png"
    #define DEBUG               PARTICLE "debug.png"

    /* Dialogues */
    #define HEAD                "./assets/head/"
    #define COLOR_LAYER         "./assets/overlay/color_layer.png"
    #define PLAYER_FACE         HEAD "Player.png"
    #define LEONARDO_FACE       HEAD "Leonardo.png"
    #define MARILYN_FACE        HEAD "Marilyn.png"

    #define IS_NORMAL(x)            (((x) == (0)) ? (1) : (0))
    #define IS_HOVER(x)             (((x) == (1)) ? (1) : (0))
    #define IS_PRESSED(x)           (((x) == (2)) ? (1) : (0))
    #define IS_RELEASED(x)          (((x) == (3)) ? (1) : (0))

    /* Settings screen */
    #define TITLE_WIDTH         320
    #define TEXT_BUTTON_WIDTH   129

#endif /* !MY_MACROS_H_ */
