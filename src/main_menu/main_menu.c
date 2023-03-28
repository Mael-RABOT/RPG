/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_menu.c
*/

#include "../../include/prototype.h"

int detect_button(button_t *button, sfEvent event)
{
    button->state = NONE;
    if (event.type == sfEvtMouseMoved)
        button->is_hover(button, &event.mouseMove);
    if (event.type == sfEvtMouseButtonPressed)
        button->is_clicked(button, &event.mouseButton);
    if (event.type == sfEvtMouseButtonReleased)
        button->is_released(button, &event.mouseButton);
    sfRectangleShape_setOutlineThickness(button->rect, 0);
    return 0;
}

static int load_texture(button_t *button, char *pathfile)
{
    button->texture = sfTexture_createFromFile(pathfile, NULL);
    sfRectangleShape_setTexture(button->rect, button->texture, sfFalse);
    sfVector2u size = sfTexture_getSize(button->texture);
    size.x /= 3;
    button->texture_rect = (sfIntRect){0, 0, size.x, size.y};
    sfRectangleShape_setTextureRect(button->rect, button->texture_rect);
    return 0;
}

button_t *create_button(sfVector2f position, sfVector2f size,
char *pathfile, void (*action)(app_t *app, int))
{
    button_t *button = malloc(sizeof(button_t));
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    button->is_clicked = &is_button_clicked;
    button->is_released = &is_button_released;
    button->is_hover = &is_button_hover;
    button->state = NONE;
    button->action = action;
    load_texture(button, pathfile);
    return button;
}
