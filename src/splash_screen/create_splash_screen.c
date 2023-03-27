/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_splash_screen
*/

#include "../../include/prototype.h"

ruined_fore_t *create_ruined_fore(void)
{
    ruined_fore_t *ruined_fore = malloc(sizeof(ruined_fore_t));

    ruined_fore->sprite = sfSprite_create();
    ruined_fore->texture = sfTexture_createFromFile(RUINED_FORE, NULL);
    sfSprite_setTexture(ruined_fore->sprite, ruined_fore->texture, sfTrue);
    return ruined_fore;
}

ruined_back_t *create_ruined_back(void)
{
    ruined_back_t *ruined_back = malloc(sizeof(ruined_back_t));

    ruined_back->sprite = sfSprite_create();
    ruined_back->texture = sfTexture_createFromFile(RUINED_BACK, NULL);
    sfSprite_setTexture(ruined_back->sprite, ruined_back->texture, sfTrue);
    return ruined_back;
}

splash_screen_t *create_splash_screen(void)
{
    splash_screen_t *splash_screen = malloc(sizeof(splash_screen_t));

    splash_screen->ruined_back = create_ruined_back();
    splash_screen->ruined_fore = create_ruined_fore();
    return splash_screen;
}
