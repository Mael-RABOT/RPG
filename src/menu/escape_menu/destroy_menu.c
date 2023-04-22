/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_menu.c
*/

#include "../../../include/prototype.h"

int destroy_escape_menu(escape_menu_t *em)
{
    destroy_button(em->button);
    free(em);
    return 0;
}
