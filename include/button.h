/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include "include.h"

    typedef enum bool {
        false = 0,
        true
    } bool_t;

    typedef enum button_state {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED
    } button_state_t;

    typedef struct button {
        sfRectangleShape *rect;
        int (*is_clicked) (struct button *, sfMouseButtonEvent *);
        int (*is_released) (struct button *, sfMouseButtonEvent *);
        int (*is_hover) (struct button *, sfMouseMoveEvent *);
        void (*action) (struct app *, int);
        button_state_t state;
        sfIntRect texture_rect;
        sfTexture *texture;
        bool_t pressed;
    } button_t;

#endif //BUTTON_H_
