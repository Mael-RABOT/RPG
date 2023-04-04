/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** enum.h
*/

#ifndef ENUM_H_
    #define ENUM_H_

    typedef enum cinematic {
        Tutorial_door,
        Death,
        Spinning_cat,
        Portal
    } cinematic_t;

    typedef enum state {
        splash = 0,
        main_menu,
        settings,
        pause_menu,
        game,
        dialogue,
        cinematics
    } state_t;

    typedef enum block {
        TRANSPARENT = 0,
        SOLID,
        STAIRS,
        PLAYER_SPAWNER,
        TELEPORTER
    } block_t;

    typedef enum map_index {
        tutorial = 0,
        hub,
        maze
    } map_index_t;

    typedef enum face {
        Player = 0,
        Leonardo,
        Marilyn
    } face_t;

#endif // ENUM_H_
