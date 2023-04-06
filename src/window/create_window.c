/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_window.c
*/

#include "../../include/prototype.h"

void add_icon(sfRenderWindow *window)
{
    sfImage* icon_image = sfImage_createFromFile(ICON);
    if (!icon_image)
        return;
    unsigned int width = sfImage_getSize(icon_image).x;
    unsigned int height = sfImage_getSize(icon_image).y;
    const sfUint8* pixels = sfImage_getPixelsPtr(icon_image);
    sfRenderWindow_setIcon(window, width, height, pixels);
}

sfRenderWindow *create_window(sfVideoMode videomode, const char *title)
{
    sfRenderWindow *window = sfRenderWindow_create(videomode, title,
        sfResize | sfClose, NULL);
    add_icon(window);
    sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
    return window;
}
