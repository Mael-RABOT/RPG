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

    /* Game State*/
    #define DEFAULT_GAME_STATE  4

    /* Time */
    #define TIME_DIVIDER        1000000.0
    #define ANIMATION_TICK      0.15

    /* Time */
    #define TIME_DIVIDER        1000000.0
    #define ANIMATION_TICK      0.15

    /* Quick Path*/
    #define IMAGES              "./assets/images/"
    #define MUSICS              "./assets/sounds/musics/"
    #define FONTS               "./assets/fonts/"
    #define BACKGROUND          "./assets/backgrounds/"

    /* Splash Screen */
    #define RUINED_BACK         IMAGES "ruined_back.png"
    #define RUINED_FORE         IMAGES "ruined_fore.png"
    #define TITLE               IMAGES "title.png"
    #define SKIP                IMAGES "skip.png"

    /* Fonts */
    #define QUICKSAND_BOLD      FONTS  "quicksand/Quicksand-Bold.otf"
    #define QUICKSAND_REGULAR   FONTS  "quicksand/Quicksand-Regular.otf"
    #define FFFFORWA            FONTS "FFFFORWA.TTF"

    /* Main Menu */
    #define RUINED_FORE_WIDTH   2880
    #define RUINED_BACK_WIDTH   2880
    #define SKIP_WIDTH          200

    #define FADE_ITERATION      50

    /* FPS Counter*/
    #define SHOW_FPS_DEFAULT    1

    /* Sounds */
    #define INTRO_MUSIC         MUSICS "intro.ogg"

    /* Backgrounds */
    #define NIGHT_SKY           BACKGROUND "night_sky.png"

    /* Cinematic */
    #define CINEMATIC           "./assets/cinematic/"
    #define TUTORIAL_DOOR       CINEMATIC "door_tutorial.png"
    #define TUTORIAL_FRAME      9
    #define DEATH_SCREEN        CINEMATIC "death_screen.png"
    #define DEATH_FRAME         17

    /* Cursor */
    #define CURSOR              "./assets/cursor.png"
    #define CURSOR_OFFSET_X     0
    #define CURSOR_OFFSET_Y     0

    /* Particle Engine */
    #define PARTICLE    "./assets/particles/"
    #define FIRE        PARTICLE "fire_sheet.png"
    #define SMOKE       PARTICLE "smoke_sheet.png"
    #define DEBUG       PARTICLE "debug.png"

#endif /* !MY_MACROS_H_ */
