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
    app->player_stats->level = my_atoi(player_vals[Level]);
    app->player_stats->hp = my_atoi(player_vals[HP]);
    app->player_stats->stamina = my_atoi(player_vals[Stamina]);
    app->player_stats->strength = my_atoi(player_vals[strength]);
    app->player_stats->dexterity = my_atoi(player_vals[dexterity]);
    app->player_stats->defense = my_atoi(player_vals[Defense]);
    app->player_stats->experience = my_atoi(player_vals[Experience]);
    app->player_stats->level_cost = my_atoi(player_vals[Level_Cost]);
    return;
}
