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

button_t *create_button(object_info_t info, void (*action)(app_t *app))
{
    button_t *button = malloc(sizeof(button_t));
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, info.position);
    sfRectangleShape_setSize(button->rect, info.size);
    button->is_clicked = &is_button_clicked;
    button->is_released = &is_button_released;
    button->is_hover = &is_button_hover;
    button->state = NONE;
    button->action = action;
    button->next_button = NULL;
    return button;
}

button_t *append_button(button_t *button, object_info_t info,
    void (*action)(app_t *app), char *texture_path)
{
    button_t *tmp_button = button;
    if (tmp_button != NULL) {
        while (button->next_button != NULL) {
            button = button->next_button;
        }
        button->next_button = create_button(info, action);
        load_button_texture(button->next_button, texture_path);
    } else {
        button = create_button(info, action);
        load_button_texture(button, texture_path);
    }
    return button;
}
