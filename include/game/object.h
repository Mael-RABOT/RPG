/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** object.h
*/

#ifndef OBJECT_H_
    #define OBJECT_H_

    #include "../prototype.h"

    typedef struct sfVector3i {
        int x;
        int y;
        int z;
    } sfVector3i;

    typedef struct sprite {
        sfSprite *sprite;
        sfTexture *texture;
    } sprite_t;

#endif
