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

static tile_t **load_tile_line(map_object_t **map_object, char *line, int index)
{
    char **array = split(line, ',');
    tile_t **tile = malloc(sizeof(tile_t *) * (len_array(array) + 1));
    int i = 0;
    while (array[i] != NULL) {
        tile[i] = create_tile(my_atoi(array[i]), map_object,
            (sfVector2i){i, index});
        i += 1;
    }
    tile[i] = NULL;
    free_array(array);
    return tile;
}

static int get_len_x(tile_t **tile)
{
    int i = 0;
    while (tile[i] != NULL) {
        i += 1;
    }
    return i;
}

int load_tile(layer_t *layer, const char *pathfile, map_object_t **map_object)
{
    int size = get_map_size(pathfile);
    layer->layer = malloc(sizeof(tile_t **) * (size + 2));
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int index = 0;
    int read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        line[read_size - 1] = '\0';
        layer->layer[index] = load_tile_line(map_object, line, index);
        index += 1;
    }
    layer->layer[index] = NULL;
    layer->size.x = get_len_x(layer->layer[0]);
    layer->size.y = index;
    free(line);
    fclose(fp);
    return 0;
}
