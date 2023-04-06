/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** map
*/

#include "../../include/prototype.h"

void get_map_name(app_t *app, char *line, size_t len, FILE *file)
{
    getline(&line, &len, file);
    app->maps->selected_map->name = line;
    return;
}
