/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** enemy_hit.c
*/

#include "../../include/prototype.h"

static int detect_hit_tile(app_t *app, tile_t *tile, float hypo)
{
    if (tile->state == ENEMY && hypo < 2)
        app->fight->no_round -= 1;
    if (tile->state == BOSS && hypo < 2)
        app->fight->no_round -= 1;
    return 0;
}

static int detect_hit_layer(app_t *app)
{
    sfVector2i position = {0, 0};
    layer_t *layer = app->maps->selected_map->layer[app->player->layer];
    entity_t *player = app->player;
    while (layer->layer[position.y] != NULL) {
        position.x = 0;
        while (layer->layer[position.y][position.x] != NULL) {
            tile_t *tile = layer->layer[position.y][position.x];
            float dx = pow(player->position.x - tile->position.x, 2);
            float dy = pow(player->position.y - tile->position.y, 2);
            float hypo = sqrt(dx + dy);
            detect_hit_tile(app, tile, hypo);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}

int enemy_hit(app_t *app, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft &&
        app->fight->is_fighting != 0) {
        detect_hit_layer(app);
    }
    return 0;
}
