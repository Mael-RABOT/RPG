/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** fps
*/

#include "../include.h"

#ifndef FPS_H_
    #define FPS_H_

    typedef struct fps {
        sfClock *clock;
        sfFont *font;
        sfText *text;
        int fps;
        int key_f;
    } fps_t;

#endif //FPS_H_
