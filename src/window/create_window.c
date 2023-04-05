/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_window.c
*/

#include "../../include/prototype.h"

sfRenderWindow *create_window(sfVideoMode videomode, const char *title)
{
    sfRenderWindow *window = sfRenderWindow_create(videomode, title,
        sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
    return window;
}
