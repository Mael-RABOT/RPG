/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** load_map.c
*/

#include "../../include/prototype.h"

layer_t *create_layer(const char *pathfile, const char *layer_path,
    map_object_t **map_object)
{
    layer_t *layer = malloc(sizeof(layer_t));
    layer->pathfile = my_strdup(pathfile);
    load_tile(layer, pathfile, map_object);
    connect_teleporter(layer_path, layer);
    return layer;
}

layer_t **load_layer(const char *pathfile, map_object_t **map_object)
{
    layer_t **layer = malloc(sizeof(layer_t *) * (count_map_layer(pathfile) + 1));
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int index = 0;
    size_t read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        line[read_size - 1] = '\0';
        if (my_strncmp(line, "layer", 5) == 0) {
            char **array = split(line, ':');
            layer[index] = create_layer(array[1], pathfile, map_object);
            index += 1;
            free_array(array);
        }
    }
    layer[index] = NULL;
    free(line);
    fclose(fp);
    return layer;
}
