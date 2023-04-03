/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** my_macros.h
*/

#ifndef MY_MACROS_H_
    #define MY_MACROS_H_

    #define BACKGROUNDS         "assets/backgrounds/"
    #define BUTTONS             "assets/buttons/main_menu/"
    #define MENU_SETTINGS       "assets/buttons/main_menu/settings/"
    #define CINEMATICS          "assets/cinematics/"
    #define FONTS               "assets/fonts/"
    #define IMAGES              "assets/images/"
    #define IRON                "assets/iron/"
    #define NATURE              "assets/nature/"
    #define NEON                "assets/nature/"
    #define EFFECTS             "assets/sounds/effects/"
    #define MUSICS              "assets/sounds/musics/"
    #define TITLES              "assets/titles/"

    #define RUINED_BACK         IMAGES "ruined_back.png"
    #define RUINED_FORE         IMAGES "ruined_fore.png"
    #define TITLE               IMAGES "title.png"
    #define SKIP                IMAGES "skip.png"
    #define RUINED_CITY         IMAGES "ruined_city.png"

    #define PLAY                BUTTONS "play.png"
    #define RESUME              BUTTONS "resume.png"
    #define SETTINGS            BUTTONS "settings.png"
    #define QUIT                BUTTONS "quit.png"

    #define RUINED_FORE_WIDTH   2880
    #define RUINED_BACK_WIDTH   2880
    #define SKIP_WIDTH          200

    #define FADE_ITERATION      50

    #define IS_NORMAL(x)            (((x) == (0)) ? (1) : (0))
    #define IS_HOVER(x)             (((x) == (1)) ? (1) : (0))
    #define IS_PRESSED(x)           (((x) == (2)) ? (1) : (0))
    #define IS_RELEASED(x)          (((x) == (3)) ? (1) : (0))

#endif /* !MY_MACROS_H_ */
