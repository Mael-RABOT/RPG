/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_escape_menu.c
*/

#include "../../../include/prototype.h"

escape_menu_t *create_escape_menu(sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    escape_menu_t *escape_menu = malloc(sizeof(escape_menu_t));
    escape_menu->button = malloc(sizeof(button_t *) * 4);
    object_info_t button_info;
    memset(&button_info, 0, sizeof(button_info));
    button_info.scale = (sfVector2f){1, 1};
    button_info.size = (sfVector2f){64 * 3, 32 * 3};
    button_info.position = (sfVector2f){window_size.x / 2 - button_info.size.x / 2, 300};
    escape_menu->button[0] = create_button(button_info, &play, RESUME);
    button_info.position = (sfVector2f){window_size.x / 2 - button_info.size.x / 2, 400};
    escape_menu->button[1] = create_button(button_info, &launch_setting, SETTING);
    escape_menu->button[2] = NULL;
    return escape_menu;
}
