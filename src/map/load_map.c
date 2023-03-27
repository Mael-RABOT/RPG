/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** load_map.c
*/

#include "../../include/prototype.h"

static int get_map_size(const char *pathfile)
{
    int no = 0;
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        no += 1;
    }
    fclose(fp);
    return no;
}

static tile_t **load_map_line(manifest_t *manifest, char *line, int line_nb)
{
    char **array = split(line, ',');
    int i = 0;
    tile_t **tile = malloc(sizeof(tile_t *) * (len_array(array) + 2));
    while (array[i] != NULL) {
        tile[i] = create_tile(my_atoi(array[i]), manifest, (sfVector2i){i, line_nb});
        i += 1;
    }
    tile[i] = NULL;
    free_array(array);
    return tile;
}

map_t *load_map_from_file(const char *pathfile, manifest_t *manifest)
{
    map_t *map = malloc(sizeof(map_t));
    map->map = malloc(sizeof(tile_t **) * (get_map_size(pathfile) + 2));
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    size_t read_size = 0;
    int index = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        map->map[index] = load_map_line(manifest, line, index);
        index += 1;
    }
    map->map[index] = NULL;
    fclose(fp);
    return map;
}
