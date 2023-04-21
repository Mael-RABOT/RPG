/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** special_block.c
*/

#include "../../../include/prototype.h"

static int detect_block_on_tile(const char *pathfile, layer_t *layer,
    sfVector2i position)
{
    tile_t *tile = layer->layer[position.y][position.x];
    switch (tile->state) {
        case TELEPORTER:
            teleporter_parser(pathfile, tile); break;
        case NPC:
            npc_parser(pathfile, tile, position); break;
        default:
            return 0;
    }
    return 0;
}

int special_block(const char *pathfile, layer_t *layer)
{
    sfVector2i position = {0, 0};
    while (layer->layer[position.y] != NULL) {
        position.x = 0;
        while (layer->layer[position.y][position.x]) {
            detect_block_on_tile(pathfile, layer, position);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}
