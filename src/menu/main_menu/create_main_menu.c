/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_main_menu.c
*/

#include "../../../include/prototype.h"

static sprite_t *create_title(sfRenderWindow *window)
{
    sprite_t *title = create_sprite(TITLE);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfSprite_setPosition(title->sprite,
    (sfVector2f){((float)window_size.x - (float)window_size.x / 2) / 2, -50});
    return title;
}

static int create_menu_sprite(sfRenderWindow *window,
    main_menu_t *main_menu, object_info_t button_info)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    button_info.size = (sfVector2f){64 * 3, 32 * 3};
    button_info.position = (sfVector2f){window_size.x / 4 * 1 + 30, 600};
    main_menu->button[0] = create_button(button_info, &play, PLAY);

    button_info.size = (sfVector2f){78 * 3, 32 * 3};
    button_info.position = (sfVector2f){window_size.x / 4 * 1.5 + 15, 600};
    main_menu->button[1] = create_button(button_info, &resume, RESUME);

    button_info.position = (sfVector2f){window_size.x / 4 * 2 + 30, 600};
    main_menu->button[2] = create_button(button_info, &settings_b, SETTING);

    button_info.size = (sfVector2f){64 * 3, 32 * 3};
    button_info.position = (sfVector2f){window_size.x / 4 * 2.5 + 40, 600};
    main_menu->button[3] = create_button(button_info, &quit, QUIT);
    main_menu->button[4] = NULL;
    return 0;
}

main_menu_t *create_main_menu(sfRenderWindow *window)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));
    object_info_t button_info;
    memset(&button_info, 0, sizeof(object_info_t));
    button_info.scale = (sfVector2f){1, 1};
    main_menu->button = malloc(sizeof(button_t) * 4);
    main_menu->ruined_city = create_sprite(RUINED_CITY);
    main_menu->title = create_title(window);
    main_menu->fade_index = 0;
    create_menu_sprite(window, main_menu, button_info);
    return main_menu;
}
