/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** load_manifest.c
*/

#include "../../include/prototype.h"

//layer:path
//id:texture_path:collision

map_object_t **load_object(const char *pathfile)
{
    map_object_t **map_object = malloc(sizeof(map_object_t) * count_manifest_object(pathfile));
    map_object[0] = NULL;
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    size_t read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        if (my_strncmp(line, "maps", 4) == 0)
            continue;
        char **array = split(line, ':');
        append_manifest(map_object, my_atoi(array[0]), array[1],
            my_atoi(array[2]));
        free_array(array);
    }
    free(line);
    return map_object;
}

map_t **load_map(const char *pathfile)
{
    map_t **map = malloc(sizeof(map_t *) * count_manifest_map(pathfile));
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int index = 0;
    size_t read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        if (my_strncmp(line, "maps", 4) == 0) {
            char **array = split(line, ':');
            map[index] = create_map(array[1], array[2]);
            map[index + 1] = NULL;
            index += 1;
            free_array(array);
        }
    }
    free(line);
    return map;
}

maps_t *load_manifest(const char *pathfile)
{
    maps_t *maps = malloc(sizeof(maps_t));
    maps->map_object = load_object(pathfile);
    maps->map = load_map(pathfile);
    return maps;
}
