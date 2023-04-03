/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** load_map.c
*/

#include "../../include/prototype.h"

layer_t *create_layer(const char *pathfile, map_object_t **map_object)
{
    layer_t *layer = malloc(sizeof(layer_t));
    layer->pathfile = my_strdup(pathfile);
    layer->layer = load_tile(pathfile, map_object);
    return layer;
}

layer_t **load_layer(const char *pathfile, map_object_t **map_object)
{
    printf("%s\n", pathfile);
    layer_t **layer = malloc(sizeof(layer_t *) * count_map_layer(pathfile));
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int index = 0;
    size_t read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        if (my_strncmp(line, "layer", 5) == 0) {
            char **array = split(line, ':');
            layer[index] = create_layer(array[1], map_object);
            layer[index + 1] = NULL;
            index += 1;
            free_array(array);
        }
    }
    free(line);
    fclose(fp);
    return layer;
}
