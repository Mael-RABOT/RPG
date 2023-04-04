/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** dialogue_manager
*/

#include "../../include/prototype.h"

face_t find_face_id(char *line)
{
    if (my_strcmp(line, "#Player") == 0)
        return Player;
    if (my_strcmp(line, "#Leonardo") == 0)
        return Leonardo;
    if (my_strcmp(line, "#Marilyn") == 0)
        return Marilyn;
    return -1;
}

char *find_head_sprite(face_t face_id)
{
    switch (face_id) {
        case Player:
            return PLAYER_FACE;
        case Leonardo:
            return LEONARDO_FACE;
        case Marilyn:
            return MARILYN_FACE;
    }
}

int update_speaker(app_t *app, sprite_t **speaker, face_t face_id)
{
    *speaker = create_sprite(find_head_sprite(face_id));
    if (!*speaker)
        return 1;
    return 0;
}

void remove_trailing_newline_or_space(char *line)
{
    line[my_strlen(line) - 1] = (line[my_strlen(line) - 1] == '\n'
        || line[my_strlen(line) - 1] == ' ')
            ? '\0' : line[my_strlen(line) - 1];
}

void scale_head_sprite(sprite_t *sprite, face_t face_id, sfVector2u size)
{
    float scale_factor = 3.0f;
    sfSprite_scale(sprite->sprite, (sfVector2f){scale_factor, scale_factor});
    if (face_id == Player) {
        sfSprite_setPosition(sprite->sprite, (sfVector2f){0, 20});
    } else {
        sfSprite_setPosition(sprite->sprite, (sfVector2f){size.y - 64, 20});
    }
}

void fill_speaker(speakers_t *speakers, char **names, sfVector2u size)
{
    face_t face_id;
    for (int i = 0; names[i] != NULL; i++) {
        face_id = find_face_id(names[i]);
        speakers->face_list[i] = create_sprite(find_head_sprite(face_id));
        scale_head_sprite(speakers->face_list[i], face_id, size);
    }
}

speakers_t *init_speakers(FILE *stream, sfVector2u size)
{
    speakers_t *speakers = malloc(sizeof(speakers_t));
    size_t len;
    char *line = NULL;
    getline(&line, &len, stream);
    remove_trailing_newline_or_space(line);
    char **names = split(line, ':');
    free(line);
    int arr_size = len_array(names);
    speakers->face_list = malloc(sizeof(sprite_t) * arr_size + 1);
    speakers->name_list = malloc(sizeof(char *) * arr_size + 1);
    fill_speaker(speakers, names, size);
    return speakers;
}

static int dialogue_loop(app_t *app, FILE *stream, sprite_t *background,
    state_t old_state)
{
    sfClock *timer = sfClock_create();
    speakers_t *speakers = init_speakers(stream, sfRenderWindow_getSize(app->window));
    while(sfRenderWindow_isOpen(app->window) && app->state == dialogue) {
        dialogue_events(app);
        sfRenderWindow_clear(app->window, sfBlack);
        display_game_dialogue(app);
        display_dialogue(app, background);
        sfRenderWindow_display(app->window);
    }
    sfClock_destroy(timer);
    return EXIT_SUCCESS;
}

int dialogue_manager(app_t *app, char *filepath)
{
    FILE *stream = fopen(filepath, "r");
    if (!stream)
        return EXIT_FAILURE;
    sprite_t *background = create_sprite(COLOR_LAYER);
    scale_sprite(app, background);
    state_t state = app->state;
    app->state = dialogue;
    dialogue_loop(app, stream, background, state);
    destroy_sprite(background);
    fclose(stream);
    return EXIT_SUCCESS;
}
