/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** background
*/

#include "../../include/prototype.h"

void change_background(background_t *background, char *filepath)
{
    background->texture = sfTexture_createFromFile(filepath, sfFalse);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
}

background_t *init_background(void)
{
    background_t *background = malloc(sizeof(background_t));
    background->sprite = sfSprite_create();
    change_background(background, NIGHT_SKY);
    return (background);
}

void display_background(app_t *app)
{
    sfRenderWindow_drawSprite(app->window, app->background->sprite, NULL);
}
