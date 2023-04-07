/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** display_button.c
*/

#include "../../include/prototype.h"

int display_button(sfRenderWindow *window, button_t **button)
{
    int i = 0;
    while (button[i] != NULL) {
        printf("%d\n", i);
        sfRenderWindow_drawRectangleShape(window, button[i]->rect, NULL);
        i += 1;
    }
    return 0;
}
