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
        sfResize | sfClose, NULL);
    return window;
}
