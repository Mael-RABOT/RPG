/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** load_tile.c
*/

#include "../../include/prototype.h"

static int get_map_size(const char *pathfile)
{
    int no = 0;
    errno = 0;
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        no += 1;
    }
    free(line);
    fclose(fp);
    return no;
}

int load_tile(const char *pathfile, map_object_t **map_object)
{
    tile_t ***tile = malloc(sizeof(tile_t **) * get_map_size(pathfile));
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
    }
    return 0;
}
