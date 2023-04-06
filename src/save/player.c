/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player
*/

#include "../../include/prototype.h"

void write_player_infos(FILE *file, player_t *player_stats)
{
    write_info(file, player_stats->level, sfFalse);
    write_info(file, player_stats->hp, sfFalse);
    write_info(file, player_stats->stamina, sfFalse);
    write_info(file, player_stats->strength, sfFalse);
    write_info(file, player_stats->dexterity, sfFalse);
    write_info(file, player_stats->defense, sfFalse);
    write_info(file, player_stats->experience, sfFalse);
    write_info(file, player_stats->level_cost, sfTrue);
    fwrite("\n", sizeof(char), 1, file);
    return;
}
