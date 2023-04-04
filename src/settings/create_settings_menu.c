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
    float half = window_size.x / 2;
    float quarter = window_size.x / 4;

    settings_menu->background = create_sprite(SETTINGS_BACKGROUND);
    settings_menu->text_sounds = create_sprite(SOUNDS_TITLE);
    settings_menu->text_resolution = create_sprite(RESOLUTION_TITLE);
    settings_menu->sounds = create_sprite(SOUND);
    button_info->size = (sfVector2f){32 * 1.8, 54 * 1.8};
    button_info->position = (sfVector2f){half - quarter + TEXT_BUTTON_WIDTH / 2, 420};
    settings_menu->sounds_more = create_button(button_info, 3, PLUS, &play);
    button_info->position = (sfVector2f){half - quarter - TEXT_BUTTON_WIDTH / 2 - button_info->size.x + 2, 420};
    settings_menu->sounds_less = create_button(button_info, 3, MINUS, &play);
    settings_menu->music = create_sprite(MUSIC);
    button_info->position = (sfVector2f){half - quarter + TEXT_BUTTON_WIDTH / 2, 610};
    settings_menu->music_more =  create_button(button_info, 3, PLUS, &play);
    button_info->position = (sfVector2f){half - quarter - TEXT_BUTTON_WIDTH / 2 - button_info->size.x + 2, 610};
    settings_menu->music_less = create_button(button_info, 3, MINUS, &play);
    button_info->size = (sfVector2f){372 / 4 * 2.9, 32 * 2.9};
    button_info->position = (sfVector2f){half + quarter - 372 / 4 * 2.9 / 2 - 160, 420};
    settings_menu->full_screen = create_button(button_info, 3, FULLSCREEN, &play);

    button_info->position = (sfVector2f){half + quarter - 372 / 4 * 2.9 / 2 + 190, 420};
    settings_menu->windowded = create_button(button_info, 3, WINDOWDED, &play);
    /*
    //button_info->size =

    button_info->position = (sfVector2f){window_size.x / 4 * 1 + 30, 600};
    settings_menu->low_resolution = create_button(button_info, 3, LOW_RESOLUTION, &play);

    button_info->position = (sfVector2f){window_size.x / 4 * 1 + 30, 600};
    settings_menu->high_resolution =  create_button(button_info, 3, HIGH_RESOLUTION, &play);*/
    return settings_menu;
}
