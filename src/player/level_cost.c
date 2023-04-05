/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** get_level_cost
*/

#include "../../include/prototype.h"

void set_level_cost(stat_t *player)
{
    int current_level = player->level;
    if (current_level >= 0 && current_level <= 15)
        player->level_cost = 2 * current_level + 7;
    if (current_level > 15 && current_level <= 30)
        player->level_cost = 5 * current_level - 38;
    if (current_level > 30)
        player->level_cost = 9 * current_level - 158;
}
