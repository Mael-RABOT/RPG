/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** display_menu.c
*/

#include "../../../include/prototype.h"

int display_escape_menu(app_t *app, escape_menu_t *escape_menu)
{
    display_button(app->window, escape_menu->button);
    return 0;
}
