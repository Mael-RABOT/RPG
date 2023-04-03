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

static tile_t **load_tile_line(map_object_t **map_object, char *line, int index, int size)
{
    char **array = split(line, ',');
    tile_t **tile = malloc(sizeof(tile_t *) * (len_array(array) + 1));
    int i = 0;
    while (array[i] != NULL) {
        tile[i] = create_tile(my_atoi(array[i]), map_object,
            (sfVector2i){index, i}, (sfVector2i){size, len_array(array)});
        tile[i + 1] = NULL;
        i += 1;
    }
    tile[index + 1] = NULL;
    free_array(array);
    return tile;
}

tile_t ***load_tile(const char *pathfile, map_object_t **map_object)
{
    int size = get_map_size(pathfile);
    tile_t ***tile = malloc(sizeof(tile_t **) * (size + 1));
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int index =  0;
    while (getline(&line, &len, fp) != -1) {
        tile[index] = load_tile_line(map_object, line, index, size);
        tile[index + 1] = NULL;
        index += 1;
    }
    fclose(fp);
    return tile;
}
