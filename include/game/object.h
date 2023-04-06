/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** object.h
*/

#ifndef OBJECT_H_
    #define OBJECT_H_

    #include "../prototype.h"

    typedef struct song {
        int id;
        char *path;
        song_type_t type;
    } song_t;

    typedef struct music {
        song_t **songs;
        int song_number;
        sfMusic *music;
    } music_t;

    typedef struct sfVector3i {
        int x;
        int y;
        int z;
    } sfVector3i;

    typedef struct sprite {
        sfSprite *sprite;
        sfTexture *texture;
    } sprite_t;

    typedef struct text {
        sfFont *font;
        sfText *text;
    } text_t;

#endif
