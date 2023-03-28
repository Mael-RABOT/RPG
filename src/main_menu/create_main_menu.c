/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_main_menu.c
*/

#include "../../include/prototype.h"

static title_t *create_title(sfRenderWindow *window)
{
    title_t *title = malloc(sizeof(title_t));
    sfVector2u window_size = sfRenderWindow_getSize(window);

    title->sprite = sfSprite_create();
    title->texture = sfTexture_createFromFile(TITLE, NULL);
    sfSprite_setTexture(title->sprite, title->texture, sfTrue);
    sfSprite_setPosition(title->sprite,
    (sfVector2f){((float)window_size.x - (float)window_size.x / 2) / 2, -50});
    return title;
}

ruined_city_t *create_ruined_city(sfRenderWindow *window)
{
    ruined_city_t *ruined_city = malloc(sizeof(ruined_city_t));
    sfVector2u window_size = sfRenderWindow_getSize(window);

    ruined_city->sprite = sfSprite_create();
    ruined_city->texture = sfTexture_createFromFile(RUINED_CITY, NULL);
    sfSprite_setTexture(ruined_city->sprite, ruined_city->texture, sfTrue);
    return ruined_city;
}

main_menu_t *create_main_menu(sfRenderWindow *window)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));

    main_menu->ruined_city = create_ruined_city(window);
    main_menu->title = create_title(window);
    main_menu->fade_index = 0;
    return main_menu;
}
