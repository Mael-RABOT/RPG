/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** map.h
*/

#include "../prototype.h"

#ifndef MAP_H_
    #define MAP_H_

    typedef struct teleport {
        char *name;
    } teleport_t;

    typedef struct npc {
        char *file;
        sfVector2i position;
    } npc_t;

    typedef struct tile {
        int id;
        block_t state;
        union {
            teleport_t *teleport;
            npc_t *npc;
        } sb;
        sfVector2f position;
        sfTexture *texture;
        sfSprite *tile;
    } tile_t;

    typedef struct layer {
        int id;
        char *pathfile;
        sfVector2f size;
        tile_t ***layer;
    } layer_t;

    typedef struct map_object {
        int id;
        char *path;
        block_t state;
        sfTexture *texture;
    } map_object_t;

    typedef struct map {
        layer_t **layer;
        char *name;
        char *path;
        sfVector2f size;
        sfVector2f spawn;
    } map_t;

    typedef struct maps {
        map_t **map;
        map_object_t **map_object;
        map_t *selected_map;
    } maps_t;

    tile_t *create_tile(int id, map_object_t **map_object, sfVector2i position);
    int destroy_tile(tile_t *tile);
    layer_t *load_map_from_file(const char *pathfile, int id,
        map_object_t **map_object, entity_t *player);
    int display_map(sfRenderWindow *window, map_t *map, entity_t *player);

    int destroy_maps(maps_t *maps);

    int count_manifest_map(const char *filepath);
    int count_manifest_object(const char *filepath);
    int count_map_layer(const char *filepath);

    int get_collision(map_object_t **map_object, int id);
    sfTexture *get_texture(map_object_t **map_object, int id);

    maps_t *load_manifest(const char *filepath);

    map_object_t *create_map_object(int id, char *path, int collision);
    int append_manifest(map_object_t **map_object, int id, char *path,
        int collision);
    map_t *create_map(const char *name, const char *path, map_object_t **mo);
    layer_t **load_layer(const char *pathfile, map_object_t **map_object);
    int load_tile(layer_t *layer, const char *pathfile,
        map_object_t **map_object);
    int change_map(app_t *app, maps_t *maps, entity_t *player, int id);
    int change_map_by_name(app_t *app, maps_t *maps, entity_t *player,
        char *name);
    int detect_spawn(map_t *map);
    int special_block(const char *pathfile, layer_t *layer);

    int destroy_map(map_t *map);

    teleport_t *create_teleport(char *map_name);
    int destroy_teleport(teleport_t *teleport);

    npc_t *create_npc(char *name, sfVector2i position);
    int destroy_npc(npc_t *npc);

    int teleporter_parser(const char *pathfile, tile_t *tile);
    int npc_parser(const char *pathfile, tile_t *tile, sfVector2i position);

#endif //MAP_H_
