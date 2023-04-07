/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_button.c
*/

#include "../../include/prototype.h"

int load_button_texture(button_t *button, char *texture_path)
{
    button->texture = sfTexture_createFromFile(texture_path, NULL);
    sfRectangleShape_setTexture(button->rect, button->texture, sfFalse);
    sfVector2u size = sfTexture_getSize(button->texture);
    size.x /= 3;
    button->texture_rect = (sfIntRect){0, 0, size.x, size.y};
    sfRectangleShape_setTextureRect(button->rect, button->texture_rect);
    return 0;
}

button_t *create_button(object_info_t info, void (*action)(app_t *app),
    char *texture_path)
{
    button_t *button = malloc(sizeof(button_t));
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, info.position);
    sfRectangleShape_setSize(button->rect, info.size);
    sfRectangleShape_setScale(button->rect, info.scale);
    button->is_clicked = &is_button_clicked;
    button->is_released = &is_button_released;
    button->is_hover = &is_button_hover;
    button->state = NONE;
    button->pressed = false;
    button->action = action;
    load_button_texture(button, texture_path);
    return button;
}
