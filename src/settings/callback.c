/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** callback
*/

#include "../../include/prototype.h"

int is_button_clicked(button_t *button, sfMouseButtonEvent *mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect);
    if (sfFloatRect_contains(&bounds, (float)mouse->x, (float)mouse->y)) {
        button->state = PRESSED;
        return 1;
    } else {
        return 0;
    }
}

int is_button_released(button_t *button, sfMouseButtonEvent *mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect);
    if (sfFloatRect_contains(&bounds, (float)mouse->x, (float)mouse->y)) {
        button->state = RELEASED;
        return 1;
    } else {
        return 0;
    }
}

int is_button_hover(button_t *button, sfMouseMoveEvent *mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect);
    if (sfFloatRect_contains(&bounds, (float)mouse->x, (float)mouse->y)) {
        button->state = HOVER;
        return 1;
    } else {
        return 0;
    }
}