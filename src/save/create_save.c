/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_save
*/

#include "../../include/prototype.h"

void write_info(FILE *file, int int_info)
{
    char *info = my_int_to_str(int_info);

    fwrite(info, sizeof(char), my_strlen(info), file);
    fwrite(":", sizeof(char), 1, file);
    return;
}

void create_save(app_t *app)
{
    int nb_save = choose_save();
    char *pathfile = malloc(sizeof(char) * 16);

    pathfile[0] = '\0';
    my_strcat(pathfile, "save/savegame_");
    my_strcat(pathfile, my_int_to_str(nb_save));
    FILE *file = fopen(pathfile, "w");
    write_map_name(file, app->maps->selected_map->name);
    write_player_infos(file, app->player->stat);
    write_weapon_infos(file, app->player->stat->weapon);
    fclose(file);
    return;
}
