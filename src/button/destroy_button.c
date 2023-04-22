/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_buttoc
*/

#include "../../include/prototype.h"

static int destroy_single_button(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    sfTexture_destroy(button->texture);
    free(button);
    return 0;
}

int destroy_button(button_t **button)
{
    int i = 0;
    while (button[i] != NULL) {
        destroy_single_button(button[i]);
        i += 1;
    }
    free(button);
    return 0;
}
