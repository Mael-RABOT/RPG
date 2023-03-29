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
    int destroy_app(app_t *app);

    /* event */
    int main_event(app_t *app);

    /* update_splash_screen */
    splash_screen_t *create_splash_screen(sfRenderWindow *window);
    int splash_screen(app_t *app, sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int skip_splash_screen(app_t *app);
    int update_ruined_back(sfRenderWindow *window,
        splash_screen_t *splash_screen);
    int update_ruined_fore(sfRenderWindow *window,
        splash_screen_t *splash_screen);
    int update_title(sfRenderWindow *window, splash_screen_t *splash_screen);
    int update_skip(sfRenderWindow *window, splash_screen_t *splash_screen);

    /* clean_splash_screen */
    int clean_splash_screen(app_t *app);

    /* map*/
    tile_t *create_tile(int id, manifest_t *manifest, sfVector2i position,
        sfVector2i size);
    int destroy_tile(tile_t *tile);
    map_t *load_map_from_file(const char *pathfile, manifest_t *manifest);
    int display_map(sfRenderWindow *window, map_t *map);

    int destroy_map(map_t *map);

    /* manifest */
    int get_collision(manifest_t *manifest, int id);
    sfTexture *get_texture(manifest_t *manifest, int id);

    manifest_t *load_manifest(const char *filepath);
    manifest_t *create_manifest(int id, char *path, int collision);
    manifest_t *append_manifest(manifest_t *manifest, int id, char *path,
        int collision);
    int destroy_manifest(manifest_t *manifest);

    /* array manipulation */
    int print_array(char **array);
    int len_array(char **array);
    int free_array(char **array);
    char **split(char *arg, char separator);

    /* main_menu */
    main_menu_t *create_main_menu(sfRenderWindow *window);
    int display_main_menu(app_t *app);
    button_t *create_button(button_info_t *info, int nb_element,
    char *pathfile, void (*action)(app_t *app, int));
    int is_button_hover(button_t *button, sfMouseMoveEvent *mouse);
    int is_button_released(button_t *button, sfMouseButtonEvent *mouse);
    int is_button_clicked(button_t *button, sfMouseButtonEvent *mouse);
    void play(app_t *app, int i);
    void resume(app_t *app, int i);
    void settings_b(app_t *app, int i);
    void quit(app_t *app, int i);

#endif //BASE_REPO_PROTOTYPE_H
