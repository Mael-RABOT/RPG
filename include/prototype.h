/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** prototype
*/

#ifndef BASE_REPO_PROTOTYPE_H
    #define BASE_REPO_PROTOTYPE_H

    #include "include.h"

    /* main */
    int my_rpg(const int ac, const char **av);
    int gloop(app_t *app);

    /* window */
    sfRenderWindow *create_window(sfVideoMode videomode, const char *title);

    /* app */
    app_t *create_app(sfVideoMode videomode);

    /* event */
    int main_event(app_t *app);

    /* map*/
    tile_t *create_tile(int id, manifest_t *manifest, sfVector2i position);
    map_t *load_map_from_file(const char *pathfile, manifest_t *manifest);
    int display_map(sfRenderWindow *window, map_t *map);

    /* manifest */
    int get_collision(manifest_t *manifest, int id);
    sfTexture *get_texture(manifest_t *manifest, int id);

    manifest_t *load_manifest(const char *filepath);
    manifest_t *create_manifest(int id, char *path, int collision);
    manifest_t *append_manifest(manifest_t *manifest, int id, char *path,
        int collision);

    /* array manipulation */
    int print_array(char **array);
    int len_array(char **array);
    int free_array(char **array);
    char **split(char *arg, char separator);

#endif //BASE_REPO_PROTOTYPE_H
