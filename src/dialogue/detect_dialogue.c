/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** detect_dialogue.c
*/

#include "../../include/prototype.h"
#include <SFML/Graphics/Texture.h>

static int detect_dialogue_tile(app_t *app, tile_t *tile, float hypo)
{
    if (tile->state == NPC && hypo < 5) {
        dialogue_manager(app, tile->sb.npc->file);
    }
    return 0;
}

static int detect_dialogue_layer(app_t *app, layer_t *layer)
{
    sfVector2i position = {0, 0};
    entity_t *player = app->player;
    while (layer->layer[position.y] != NULL) {
        position.x = 0;
        while (layer->layer[position.y][position.x] != NULL) {
            tile_t *tile = layer->layer[position.y][position.x];
            float dx = pow(player->position.x - tile->position.x, 2);
            float dy = pow(player->position.y - tile->position.y, 2);
            float hypo = sqrt(dx + dy);
            detect_dialogue_tile(app, tile, hypo);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}

int detect_dialogue(app_t *app)
{
    if (app->menu->state != game || app->fight->is_fighting != 0)
        return 0;
    map_t *map = app->maps->selected_map;
    int i = 0;
    while (map->layer[i] != NULL) {
        detect_dialogue_layer(app, map->layer[i]);
        i += 1;
    }
    return 0;
}
