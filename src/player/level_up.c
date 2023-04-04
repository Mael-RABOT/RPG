/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** level_up
*/

#include "../../include/prototype.h"

int level_up(player_t *player)
{
    if (player->experience < player->level_cost)
        return EXIT_FAILURE;
    player->experience -= player->level_cost;
    player->level += 1;
    set_level_cost(player);
}
