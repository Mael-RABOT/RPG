/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** states.c
*/

#include "../../include/prototype.h"

int main_menu_click(main_menu_t *main_menu, sfMouseButtonEvent *button_event)
{
    main_menu->play->is_clicked(main_menu->play, button_event);
    main_menu->resume->is_clicked(main_menu->resume, button_event);
    main_menu->settings->is_clicked(main_menu->settings, button_event);
    main_menu->quit->is_clicked(main_menu->quit, button_event);
    return 0;
}

int main_menu_release(main_menu_t *main_menu, sfMouseButtonEvent *button_event)
{
    main_menu->play->is_released(main_menu->play, button_event);
    main_menu->resume->is_released(main_menu->resume, button_event);
    main_menu->settings->is_released(main_menu->settings, button_event);
    main_menu->quit->is_released(main_menu->quit, button_event);
    return 0;
}

int main_menu_hover(main_menu_t *main_menu, sfMouseMoveEvent *move_event)
{
    main_menu->play->is_hover(main_menu->play, move_event);
    main_menu->resume->is_hover(main_menu->resume, move_event);
    main_menu->settings->is_hover(main_menu->settings, move_event);
    main_menu->quit->is_hover(main_menu->quit, move_event);
    return 0;
}
