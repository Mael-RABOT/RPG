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
    int random_randint(int min, int max);

    int generator(int x, int y, int perfect);

    /* window */
    sfRenderWindow *create_window(sfVideoMode videomode, const char *title);

    /* app */
    app_t *create_app(sfVideoMode videomode);
    int destroy_app(app_t *app);
    int destroy_game(app_t *app);

    /* button */
    button_t *create_button(object_info_t info, void (*action)(app_t *app),
        char *texture_path);
    int load_button_texture(button_t *button, char *pathfile);
    int display_button(sfRenderWindow *window, button_t **button);

    int button_event(app_t *app, button_t **button, sfEvent event);

    int update_buttons_texture(button_t **button);

    int is_button_hover(button_t *button, sfMouseMoveEvent mouse);
    int is_button_released(button_t *button, sfMouseButtonEvent mouse);
    int is_button_clicked(button_t *button, sfMouseButtonEvent mouse);

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
    int move_top(app_t *app, entity_t *player);
    int move_bot(app_t *app, entity_t *player);
    int move_left(app_t *app, entity_t *player);
    int move_right(app_t *app, entity_t *player);
    int detect_collision(app_t *app, entity_t *entity);

    int menu_event(app_t *app, sfEvent event);

    /* map*/
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
    void create_music_handler(app_t *app);
    int launch_sound(app_t *app, int id);
    void stop_sound(app_t *app);
    void close_sound(app_t *app);

    /* fight */
    fight_t *create_fight(void);
    int destroy_fight(fight_t *fight);

    int corrupt_map(app_t *app);
    int trapped_tile(app_t *app);
    int fight(app_t *app);

    /* Pathfinding */
    int pathfinder(app_t *app);

    /* Object */
    sprite_t *create_sprite(const char *pathfile);
    int destroy_sprite(sprite_t *sprite);
    text_t *create_text(const char *pathfile, int size, sfColor color,
    char *texts);

    /* entity */
    entity_t *create_entity(app_t *app, const char *pathfile,
        player_preset_t preset, weapon_type_t type);
    int destroy_entity(entity_t *entity);
    int move_player(app_t *app, sfEvent event);
    entity_t **create_enemy(void);

    /* view */
    sfView *create_view(sfVector2f size);
    int center_view(sfView *view, entity_t *player);

    /* Conversion */
    int set_isometric_pos(entity_t *entity, sfVector2f position);
    sfVector2f get_isometric_pos(sfVector2f position);

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

    /* escape menu */
    void launch_main_menu(app_t *app);
    escape_menu_t *create_escape_menu(sfRenderWindow *window);
    int display_escape_menu(app_t *app, escape_menu_t *escape_menu);
    void launch_setting(app_t *app);

    /* Settings */
    settings_menu_t *create_settings_menu(sfRenderWindow *window);
    void display_settings_menu(sfRenderWindow *window, settings_menu_t *menu);
    void update_settings_menu(settings_menu_t *, sfRenderWindow *);

    void toggle_windowed(app_t *app);
    void toggle_borderless(app_t *app);
    void toggle_fullscreen(app_t *app);

    void increase_music_volume(app_t *app);
    void decrease_music_volume(app_t *app);
    void increase_global_volume(app_t *app);
    void decrease_global_volume(app_t *app);

    void nothing(app_t *app);

    void sound_settings(settings_menu_t *settings_menu, object_info_t
        button_info, sfVector2u window_size);
    void music_settings(settings_menu_t *settings_menu, object_info_t
        button_info, sfVector2u window_size);
    void resolution_settings(settings_menu_t *settings_menu,
        object_info_t button_info, sfVector2u window_size);



    /* Dialogues */
    int detect_dialogue(app_t *app);
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

    /* main_menu */
    main_menu_t *create_main_menu(sfRenderWindow *window);
    int display_main_menu(app_t *app);
    void play(app_t *app);
    void resume(app_t *app);
    void settings_b(app_t *app);
    void quit(app_t *app);

    int update_all_buttons_textures(app_t *app);
    int main_menu_buttons_actions(app_t *app);

    /* Player */
    stat_t *create_player(app_t *app, player_preset_t preset);
    void attack(stat_t *attacker, stat_t *defender);
    weapon_t *create_weapon(weapon_type_t type);
    void set_level_cost(stat_t *player);
    int level_up(stat_t *player);
    void apply_strength(stat_t *player);
    void apply_dexterity(stat_t *player);
    void apply_default(stat_t *player);

    /* Credits */
    void credits(app_t *app);

    /* Save */
    int choose_save(void);
    void create_save(app_t *app);
    void write_info(FILE *file, int int_info);
    void create_save(app_t *app);
    void write_map_name(FILE *file, char *map_name);
    void write_player_infos(FILE *file, stat_t *player_stats);
    void write_weapon_infos(FILE *file, weapon_t *weapon);
    int save_exist(char *pathfile);

    /* Load */
    int load_save(app_t *app, char *pathfile);
    void get_map_name(app_t *app, char *line, size_t len, FILE *file);
    void get_player_infos(app_t *app, char *line, size_t len, FILE *file);
    void get_weapon_infos(app_t *app, char *line, size_t len, FILE *file);

    /* Character selection */
    void character_selection(app_t *app);
    void stat_default_button(app_t *app);
    void stat_strength_button(app_t *app);
    void stat_dexterity_button(app_t *app);

    /* Weapons */
    void create_weapons_list(app_t *app);

#endif //BASE_REPO_PROTOTYPE_H
