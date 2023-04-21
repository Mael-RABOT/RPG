/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** npc.c
*/

#include "../../../include/prototype.h"

static int is_npc(tile_t *tile, char *line, sfVector2i position)
{
    if (my_strncmp(line, "npc", 3) == 0) {
        char **array = split(line, ':');
        tile->sb.npc = create_npc(array[2], position);
        free_array(array);
    }
    return 0;
}

int npc_parser(const char *pathfile, tile_t *tile, sfVector2i position)
{
    tile->state = NPC;
    FILE *fp = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    int read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        if (line[read_size - 1] == '\n')
            line[read_size - 1] = '\0';
        is_npc(tile, line, position);
        free(line);
        line = NULL;
    }
    return 0;
}
