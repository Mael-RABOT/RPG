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
    free(line);
    fclose(fp);
    return no;
}

static tile_t **load_map_line(map_object_t **map_object, char *line,
    sfVector2i array_info, entity_t *player)
{
    char **array = split(line, ',');
    int size_2 = len_array(array);
    int i = 0;
    tile_t **tile = malloc(sizeof(tile_t *) * (len_array(array) + 2));
    while (array[i] != NULL) {
        if (my_strcmp(array[i], "P") == 0) {
            set_isometric_pos(player, (sfVector2f){i, array_info.x},
                (sfVector2f){size_2, array_info.y});
            my_strcpy(array[i], "-1");
        }
        tile[i] = create_tile(my_atoi(array[i]), map_object, (sfVector2i){i,
            array_info.x}, (sfVector2i){size_2, array_info.y});
        i += 1;
    }
    tile[i] = NULL;
    free_array(array);
    return tile;
}

layer_t *load_map_from_file(const char *pathfile, int id,
    map_object_t **map_object, entity_t *player)
{
    int size = get_map_size(pathfile);
    layer_t *layer = malloc(sizeof(layer_t));
    layer->layer = malloc(sizeof(tile_t **) * (size + 2));
    layer->id = id;
    layer->filepath = strdup(pathfile);
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    size_t read_size = 0;
    int index = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        line[read_size - 1] = '\0';
        layer->layer[index] = load_map_line(map_object, line,
            (sfVector2i){index, size}, player);
        layer->layer[index + 1] = NULL;
        index += 1;
    }
    free(line);
    layer->layer[index] = NULL;
    fclose(fp);
    return layer;
}
