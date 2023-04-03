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

int update_dialogue(app_t *app, FILE *stream, sprite_t *speaker)
{
    size_t len;
    char *line = NULL;
    if (getline(&line, &len, stream) == -1)
        return -1;
    remove_trailing_newline_or_space(line);
    face_t face_id = find_face_id(line);
    if (face_id != -1)
        update_speaker(app, &speaker, face_id);
    if (face_id == -1)
        printf("line: %s\n", line);
    free(line);
    return 0;
}

int update_text(app_t *app, FILE *stream, sfClock *timer, sprite_t *speaker)
{
    if (sfClock_getElapsedTime(timer).microseconds / TIME_DIVIDER < 1.5)
        return 0;
    if (update_dialogue(app, stream, speaker) == -1)
        return -1;
    sfClock_restart(timer);
    return 0;
}

static int dialogue_loop(app_t *app, FILE *stream, sprite_t *background,
    state_t old_state)
{
    sfClock *timer = sfClock_create();
    sprite_t *speaker = create_sprite(PLAYER_FACE);
    while(sfRenderWindow_isOpen(app->window) && app->state == dialogue) {
        dialogue_events(app);
        sfRenderWindow_clear(app->window, sfBlack);
        display_game_dialogue(app);
        display_dialogue(app, background);
        if (update_text(app, stream, timer, speaker) == -1)
            app->state = old_state;
        sfRenderWindow_drawSprite(app->window, speaker->sprite, NULL);
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
