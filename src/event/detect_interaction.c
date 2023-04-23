/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** detect_interraction.c
*/

#include "../../include/prototype.h"

static int detect_interaction_tile(app_t *app, tile_t *tile, float hypo)
{
    if (hypo < 5) {
        if (tile->state == ENEMY || tile->state == BOSS || tile->state == NPC) {
            sfVector2f position =
                sfSprite_getPosition(app->player->sprite->sprite);
            position.y -= 20;
            sfSprite_setPosition(app->interact->sprite, position);
            sfRenderWindow_drawSprite(app->window, app->interact->sprite, NULL);
        }
    }
    return 0;
}

static int detect_interaction_layer(app_t *app)
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
            detect_interaction_tile(app, tile, hypo);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}

int detect_interaction(app_t *app)
{
    if (app->menu->state == game && app->fight->is_fighting == 0)
        detect_interaction_layer(app);
    return 0;
}
