/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_main_menu.c
*/

#include "../../include/prototype.h"

static sprite_t *create_title(sfRenderWindow *window)
{
    sprite_t *title = create_sprite(TITLE);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfSprite_setPosition(title->sprite,
    (sfVector2f){((float)window_size.x - (float)window_size.x / 2) / 2, -50});
    return title;
}

main_menu_t *create_main_menu(sfRenderWindow *window)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));
    object_info_t button_info;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    main_menu->button = NULL;
    button_info.size = (sfVector2f){64 * 3, 32 * 3};
    main_menu->ruined_city = create_sprite(RUINED_CITY);
    main_menu->title = create_title(window);
    main_menu->fade_index = 0;
    button_info.position = (sfVector2f){window_size.x / 4 * 1 + 30, 600};
    main_menu->button = append_button(main_menu->button, button_info, &play,
        PLAY);
    button_info.position = (sfVector2f){window_size.x / 4 * 1.5 + 15, 600};
    button_info.size = (sfVector2f){78 * 3, 32 * 3};
    append_button(main_menu->button, button_info, &resume, RESUME);
    button_info.position = (sfVector2f){window_size.x / 4 * 2 + 30, 600};
    append_button(main_menu->button, button_info, &settings_b, SETTING);
    button_info.position = (sfVector2f){window_size.x / 4 * 2.5 + 40, 600};
    button_info.size = (sfVector2f){64 * 3, 32 * 3};
    append_button(main_menu->button, button_info, &quit, QUIT);
    return main_menu;
}
