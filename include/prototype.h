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
    int choose_state(app_t *app);
    int gloop(app_t *app);

    int generator(int x, int y, int perfect);

    /* window */
    sfRenderWindow *create_window(sfVideoMode videomode, const char *title);

    /* app */
    app_t *create_app(sfVideoMode videomode);
    int destroy_app(app_t *app);
    int destroy_game(app_t *app);

    /* splash_screen */
    splash_screen_t *create_splash_screen(sfRenderWindow *window);
    int splash_screen(app_t *app, sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int skip_splash_screen(app_t *app);

    /* update_splash_screen */
    int update_ruined_back(sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int update_ruined_fore(sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int update_title(sfRenderWindow *window, splash_screen_t *splash_screen);
    int update_skip(sfRenderWindow *window, splash_screen_t *splash_screen);

    /* clean_splash_screen */
    int clean_splash_screen(app_t *app);

    /* event */
    int main_event(app_t *app);
    int detect_collision(app_t *app, entity_t *player, maps_t *maps);

    /* map*/
    tile_t *create_tile(int id, map_object_t **map_object, sfVector2i position,
        sfVector2i size);
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
    int change_map_by_name(app_t *app, maps_t *maps, entity_t *player, char *name);
    int detect_spawn(map_t *map);

    int destroy_map(map_t *map);

    teleport_t *create_teleport(int id);
    int destroy_teleport(teleport_t *teleport);
    int connect_teleporter(const char *pathfile, layer_t *layer);

    /* array manipulation */
    int print_array(char **array);
    int len_array(char **array);
    int free_array(char **array);
    char **split(char *arg, char separator);

    /* fps */
    void show_fps(app_t *app);
    void get_fps(app_t *app);
    char *my_int_to_str(int nb);
    void destroy_fps(fps_t *fps);

    /* Musics */
    int launch_startup_sound(app_t *app);

    /* Pathfinding */
    int pathfinder(app_t *app);

    /* Object */
    sprite_t *create_sprite(const char *pathfile);
    int destroy_sprite(sprite_t *sprite);

    /* entity */
    entity_t *create_entity(const char *pathfile);
    int destroy_entity(entity_t *entity);
    int move_player(app_t *app, sfEvent event);

    /* view */
    sfView *create_view(sfVector2f size);
    int center_view(sfView *view, entity_t *player);

    /* Conversion */
    int set_isometric_pos(entity_t *entity, sfVector2f position,
        sfVector2f size);
    sfVector2f get_isometric_pos(sfVector2f position, sfVector2f size);

    /* Background */
    void change_background(sprite_t *background, char *filepath);
    void display_background(app_t *app);
    void destroy_background(app_t *app);

    /* Cinematics */
    int launch_cinematic(app_t *app, cinematic_t cinematic_type);
    char *get_cinematic_path(cinematic_t cinematic_type);
    int find_max_frame(cinematic_t cinematic_type);
    char *get_cinematic_path(cinematic_t cinematic_type);
    int find_max_frame(cinematic_t cinematic_type);
    void destroy_cinematic(sprite_t *sprite, sfClock *clock);
    void cinematic_event(sfRenderWindow *window);

    /* Cursor */
    void create_cursor(app_t *app);
    void update_cursor(app_t *app);

    /* Particle */
    void add_particle(app_t *app, sfVector2f position, char* filepath,
        sfBool isometric);
    void update_particle(app_t *app);
    void clean_particle_list(app_t *app);

    /* Dialogues */
    int dialogue_manager(app_t *app, char *filepath);
    void display_game_dialogue(app_t *app);
    void display_dialogue(app_t *app, sprite_t *background,
        speakers_t *speakers);
    void scale_sprite(app_t *app, sprite_t *background);
    void dialogue_events(app_t *app);
    speakers_t *init_speakers(app_t *app, FILE *stream, sfVector2u size);
    face_t find_face_id(char *line);
    char *find_head_sprite(face_t face_id);
    sfVector2f find_head_position(app_t *app, sfBool player);
    sfVector2f find_text_position(app_t *app);

    /* String */
    void remove_trailing_newline_or_space(char *line);

    /* sfText */
    sfText *init_text(sfVector2f position, int size);

#endif //BASE_REPO_PROTOTYPE_H
