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
        Death
    } cinematic_t;

    typedef enum state {
        splash = 0,
        main_menu,
        settings,
        pause_menu,
        game,
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

#endif
