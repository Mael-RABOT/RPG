/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** splash_screen
*/

#include "../../include/prototype.h"

int splash_screen(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    sfRenderWindow_drawSprite(window, splash_screen->ruined_back->sprite, NULL);
    sfRenderWindow_drawSprite(window, splash_screen->ruined_fore->sprite, NULL);
    return 0;
}
