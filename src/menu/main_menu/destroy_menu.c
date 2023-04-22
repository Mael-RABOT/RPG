/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_menu.c
*/

#include "../../../include/prototype.h"

int destroy_main_menu(main_menu_t *mm)
{
    destroy_button(mm->button);
    destroy_sprite(mm->ruined_city);
    destroy_sprite(mm->title);
    free(mm);
    return 0;
}
