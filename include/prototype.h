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

    app_menu_t *create_menu(app_t *app);
    int destroy_menu(app_menu_t *am);

    /* window */
    sfRenderWindow *create_window(sfVideoMode videomode, const char *title);

    /* app */
    app_t *create_app(sfVideoMode videomode);
    int create_ui(app_t *app);
    int destroy_app(app_t *app);
    int destroy_game(app_t *app);

    /* event */
    int detect_interaction(app_t *app);

    int main_event(app_t *app);
    int move_top(app_t *app, entity_t *player);
    int move_bot(app_t *app, entity_t *player);
    int move_left(app_t *app, entity_t *player);
    int move_right(app_t *app, entity_t *player);
    int detect_collision(app_t *app, entity_t *entity);

    int menu_event(app_t *app, sfEvent event);

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
    int enemy_hit(app_t *app, sfEvent event);
    fight_t *create_fight(void);
    int destroy_fight(fight_t *fight);

    int detect_fight(app_t *app);
    int corrupt_map(app_t *app);
    int trapped_tile(app_t *app);
    int fight(app_t *app);
    int restore_tile(app_t *app);
    int kill_player(app_t *app);
    int launch_fight(app_t *app, int type);
    int stop_fight(app_t *app);

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
    int destroy_weapons(weapon_t **weapons);

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
