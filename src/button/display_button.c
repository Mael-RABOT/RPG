/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** display_button.c
*/

#include "../../include/prototype.h"

int display_button(sfRenderWindow *window, button_t *button)
{
    if (button == NULL) {
        return 0;
    } else {
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        return display_button(window, button->next_button);
    }
}
