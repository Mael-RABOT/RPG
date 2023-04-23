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
    int size = count_manifest_object(pathfile);
    map_object_t **map_object = malloc(sizeof(map_object_t) * (size + 1));
    map_object[0] = NULL;
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        line[read_size - 1] = '\0';
        if (my_strncmp(line, "maps", 4) == 0)
            continue;
        char **array = split(line, ':');
        append_manifest(map_object, my_atoi(array[0]), array[1],
            my_atoi(array[2]));
        free_array(array);
    }
    free(line);
    fclose(fp);
    return map_object;
}

map_t **load_map(const char *pathfile, map_object_t **map_object)
{
    map_t **map = malloc(sizeof(map_t *) * (count_manifest_map(pathfile) + 1));
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int index = 0;
    int read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        remove_trailing_newline_or_space(line);
        if (my_strncmp(line, "maps", 4) == 0) {
            char **array = split(line, ':');
            map[index] = create_map(array[1], array[2], map_object);
            detect_spawn(map[index]);
            index += 1;
            free_array(array);
        }
    }
    map[index] = NULL;
    free(line);
    fclose(fp);
    return map;
}

maps_t *load_manifest(const char *pathfile)
{
    maps_t *maps = malloc(sizeof(maps_t));
    maps->map_object = load_object(pathfile);
    maps->map = load_map(pathfile, maps->map_object);
    return maps;
}
