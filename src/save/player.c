/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player
*/

#include "../../include/prototype.h"

void write_player_infos(FILE *file, player_t *player_stats)
{
    write_info(file, player_stats->level);
    write_info(file, player_stats->hp);
    write_info(file, player_stats->stamina);
    write_info(file, player_stats->strength);
    write_info(file, player_stats->dexterity);
    write_info(file, player_stats->defense);
    write_info(file, player_stats->experience);
    write_info(file, player_stats->level_cost);
    fwrite("\n", sizeof(char), 1, file);
    return;
}
