/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** splash_screen
*/

#ifndef SPLASH_SCREEN_H_
    #define SPLASH_SCREEN_H_

    #include "include.h"

    typedef struct ruined_back {
        sfSprite *sprite;
        sfTexture *texture;
    } ruined_back_t;

    typedef struct ruined_fore {
        sfSprite *sprite;
        sfTexture *texture;
    } ruined_fore_t;

    typedef struct title {
        sfSprite *sprite;
        sfTexture *texture;
    } title_t;

    typedef struct skip {
        sfSprite *sprite;
        sfTexture *texture;
    } skip_t;

    typedef struct splash_screen {
        ruined_back_t *ruined_back;
        ruined_fore_t *ruined_fore;
        title_t *title;
        skip_t *skip;
        int fade_index;
        int fade_index_skip;
        int increment;
        sfClock *clock;
        sfTime time;
        float seconds;
    } splash_screen_t;

#endif //SPLASH_SCREEN_H_
