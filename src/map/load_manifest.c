/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** load_manifest.c
*/

#include "../../include/prototype.h"

//layer:path
//id:texture_path:collision

int get_layer(map_t *map, const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    int read_size = 0;
    int index = 0;
    getline(&line, &len, fp);
    while ((read_size = getline(&line, &len, fp)) != -1) {
        line[read_size - 1] = '\0';
        if (my_strncmp(line, "layer", 5) == 0) {
            map->layer[index] = load_map_from_file(&line[6], index,
                map->map_object);
            map->layer[index + 1] = NULL;
            index += 1;
        }
    }
    return 0;
}

map_t *alloc_map(const char *filepath)
{
    map_t *map = malloc(sizeof(map_t));
    int no_layer = count_manifest_layer(filepath) + 2;
    int no_object = count_manifest_object(filepath) + 2;
    map->layer = malloc(sizeof(layer_t *) * no_layer);
    map->map_object = malloc(sizeof(map_object_t *) * no_object);
    map->layer[0] = NULL;
    map->map_object[0] = NULL;
    return map;
}

static int parse_line(map_object_t **map_object, char *line)
{
    char **array = split(line, ':');
    append_manifest(map_object, my_atoi(array[0]), array[1], my_atoi(array[2]));
    free_array(array);
    return 0;
}

map_t *load_manifest(const char *filepath)
{
    map_t *map = alloc_map(filepath);
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    int read_size = 0;
    getline(&line, &len, fp);
    while ((read_size = getline(&line, &len, fp)) != -1) {
        line[read_size - 1] = '\0';
        if (my_strncmp(line, "layer", 5) != 0)
            parse_line(map->map_object, line);
    }
    free(line);
    fclose(fp);
    get_layer(map, filepath);
    return map;
}
