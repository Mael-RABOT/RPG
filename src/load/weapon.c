/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** weapon
*/

#include "../../include/prototype.h"

void get_weapon_infos(app_t *app, char *line, size_t len, FILE *file)
{
    char **weapon_vals;

    getline(&line, &len, file);
    weapon_vals = split(line, ':');
    app->player->stat->weapon->damage_point =
    my_atoi(weapon_vals[Damage_Point]);
    app->player->stat->weapon->tier = my_atoi(weapon_vals[normal]);
    app->player->stat->weapon->scaling = my_atoi(weapon_vals[scale_strength]);
    return;
}
