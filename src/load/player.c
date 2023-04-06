/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player
*/

#include "../../include/prototype.h"

void get_player_infos(app_t *app, char *line, size_t len, FILE *file)
{
    char **player_vals;

    getline(&line, &len, file);
    player_vals = split(line, ':');
    app->player->stat->level = my_atoi(player_vals[Level]);
    app->player->stat->hp = my_atoi(player_vals[HP]);
    app->player->stat->stamina = my_atoi(player_vals[Stamina]);
    app->player->stat->strength = my_atoi(player_vals[strength]);
    app->player->stat->dexterity = my_atoi(player_vals[dexterity]);
    app->player->stat->defense = my_atoi(player_vals[Defense]);
    app->player->stat->experience = my_atoi(player_vals[Experience]);
    app->player->stat->level_cost = my_atoi(player_vals[Level_Cost]);
    return;
}
