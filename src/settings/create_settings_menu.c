/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_settings_menu
*/

#include "../../include/prototype.h"

static int load_texture(button_t *button, char *pathfile, int nb_element)
{
    button->texture = sfTexture_createFromFile(pathfile, NULL);
    sfRectangleShape_setTexture(button->rect, button->texture, sfFalse);
    sfVector2u size = sfTexture_getSize(button->texture);
    size.x /= nb_element;
    button->texture_rect = (sfIntRect){0, 0, size.x, size.y};
    sfRectangleShape_setTextureRect(button->rect, button->texture_rect);
    return 0;
}

button_t *create_button(button_info_t *info, int nb_element,
char *pathfile, void (*action)(app_t *app))
{
    button_t *button = malloc(sizeof(button_t));
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, info->position);
    sfRectangleShape_setSize(button->rect, info->size);
    button->is_clicked = &is_button_clicked;
    button->is_released = &is_button_released;
    button->is_hover = &is_button_hover;
    button->state = NONE;
    button->action = action;
    load_texture(button, pathfile, nb_element);
    return button;
}

void play(app_t *app)
{
    return;
}

settings_menu_t *create_settings_menu(sfRenderWindow *window)
{
    settings_menu_t *settings_menu = malloc(sizeof(settings_menu_t));
    button_info_t *button_info = malloc(sizeof(button_info_t));
    sfVector2u window_size = sfRenderWindow_getSize(window);

    settings_menu->background = create_sprite(SETTINGS_BACKGROUND);
    sound_settings(settings_menu, button_info, window_size);
    music_settings(settings_menu, button_info, window_size);
    resolution_settings(settings_menu, button_info, window_size);
    update_settings_menu(settings_menu, window);
    return settings_menu;
}
