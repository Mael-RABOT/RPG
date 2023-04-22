/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_splash_screen
*/

#include "../../../include/prototype.h"

int destroy_splash_screen(splash_screen_t *ss)
{
    destroy_sprite(ss->ruined_back);
    destroy_sprite(ss->ruined_fore);
    destroy_sprite(ss->title);
    destroy_sprite(ss->skip);
    sfClock_destroy(ss->clock);
    free(ss);
    return 0;
}
