/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_menu.c
*/

#include "../../../include/prototype.h"

int destroy_settings_menu(settings_menu_t *sm)
{
    destroy_sprite(sm->background);
    destroy_sprite(sm->text_sounds);
    destroy_sprite(sm->text_resolution);
    destroy_sprite(sm->sounds);
    destroy_sprite(sm->music);
    destroy_button(sm->button);
    return 0;
}
