/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** load_save
*/

#include "../../include/prototype.h"

int load_save(app_t *app, char *pathfile)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;

    if (!save_exist(pathfile))
        return 1;
    file = fopen(pathfile, "r");
    get_map_name(app, line, len, file);
    get_player_infos(app, line, len, file);
    get_weapon_infos(app, line, len, file);
    fclose(file);
    return 0;
}
