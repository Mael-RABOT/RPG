/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** connect_teleporter.c
*/

#include "../../../include/prototype.h"

static int connect_teleporter_tile_condition(tile_t *tile, char *line)
{
    if (my_strncmp(line, "teleport", 8) == 0) {
        char **array = split(line, ':');
        if (my_atoi(array[1]) == tile->id) {
            tile->teleport = create_teleport(my_atoi(array[1]));
            tile->teleport->name = my_strdup(array[2]);
            free_array(array);
        } else {
            free_array(array);
        }
    }
    return 0;
}

static int connect_teleporter_tile(const char *pathfile, tile_t *tile)
{
    if (tile->state != TELEPORTER)
        return 0;
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        line[read_size - 1] = '\0';
        connect_teleporter_tile_condition(tile, line);
        free(line);
        line = NULL;
    }
    return 0;
}

int connect_teleporter(const char *pathfile, layer_t *layer)
{
    int i = 0;
    while (layer->layer[i] != NULL) {
        int j = 0;
        while (layer->layer[i][j]) {
            connect_teleporter_tile(pathfile, layer->layer[i][j]);
            j += 1;
        }
        i += 1;
    }
    return 0;
}
