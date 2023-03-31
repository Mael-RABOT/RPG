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
        tutorial,
        game,
        cinematics
    } state_t;

#endif
