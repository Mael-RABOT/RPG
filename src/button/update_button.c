/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** update_button.c
*/

#include "../../include/prototype.h"

int update_buttons_textures(button_t *button)
{
    sfIntRect new_rect = button->texture_rect;
    size_t offset_x = new_rect.width;
    if (IS_HOVER(button->state))
        new_rect.left = offset_x;
    if (IS_PRESSED(button->state))
        new_rect.left = offset_x * 2;
    if (IS_NORMAL(button->state))
        new_rect.left = 0;
    if (IS_RELEASED(button->state))
        new_rect.left = 0;
    sfRectangleShape_setTextureRect(button->rect, new_rect);
    return 0;
}

int update_button_texture(app_t *app, button_t **button)
{
    int i = 0;
    while (button[i] != NULL) {
        update_buttons_textures(button[i]);
        i += 1;
    }
    return 0;
}
