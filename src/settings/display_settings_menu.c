/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** display_settings_menu
*/

#include "../../include/prototype.h"

void display_settings_menu(sfRenderWindow *window, settings_menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->text_sounds->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->text_resolution->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->sounds->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->music->sprite, NULL);
    display_button(window, menu->button);
    return;
}
