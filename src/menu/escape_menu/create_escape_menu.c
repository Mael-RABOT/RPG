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
    object_info_t bi;
    memset(&bi, 0, sizeof(bi));
    bi.scale = (sfVector2f){1, 1};
    bi.size = (sfVector2f){64 * 3, 32 * 3};
    bi.position = (sfVector2f){window_size.x / 2 - bi.size.x / 2, 300};
    escape_menu->button[0] = create_button(bi, &play, RESUME);
    bi.position = (sfVector2f){window_size.x / 2 - bi.size.x / 2, 400};
    escape_menu->button[1] = create_button(bi, &launch_setting, SETTING);
    bi.position = (sfVector2f){window_size.x / 2 - bi.size.x / 2, 500};
    escape_menu->button[2] = create_button(bi, &launch_main_menu, MAIN_MENU);
    escape_menu->button[3] = NULL;
    return escape_menu;
}
