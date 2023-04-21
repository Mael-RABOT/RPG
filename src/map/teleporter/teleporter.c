/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** connect_teleporter.c
*/

#include "../../../include/prototype.h"

static int is_teleporter(tile_t *tile, char *line)
{
    if (my_strncmp(line, "teleport", 8) == 0) {
        char **array = split(line, ':');
        tile->sb.teleport = create_teleport(array[2]);
        free_array(array);
    }
    return 0;
}

int teleporter_parser(const char *pathfile, tile_t *tile)
{
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        if (line[read_size - 1] == '\n')
            line[read_size - 1] = '\0';
        is_teleporter(tile, line);
        free(line);
        line = NULL;
    }
    return 0;
}
