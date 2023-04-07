/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_escape_menu.c
*/

#include "../../../include/prototype.h"

escape_menu_t *create_escape_menu(void)
{
    escape_menu_t *escape_menu = malloc(sizeof(escape_menu_t));
    escape_menu->button = malloc(sizeof(button_t *) * 4);
    return escape_menu;
}
