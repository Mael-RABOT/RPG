/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** dialogue_manager
*/

#include "../../include/prototype.h"

int update_speaker(app_t *app, sprite_t **speaker, face_t face_id)
{
    *speaker = create_sprite(find_head_sprite(face_id));
    if (!*speaker)
        return 1;
    return 0;
}

void update_text(app_t  *app, speakers_t *speakers, char *line)
{
    sfText_setString(speakers->text, line);
    sfRenderWindow_drawText(app->window, speakers->text, NULL);
}

int update_dialogue(app_t *app, speakers_t *speakers, FILE *stream,
    sfClock *timer)
{
    if (sfClock_getElapsedTime(timer).microseconds / TIME_DIVIDER < 0.7f)
        return 0;
    size_t len;
    char *line = NULL;
    if (getline(&line, &len, stream) == -1) {
        app->menu->state = game;
        return 1;
    }
    remove_trailing_newline_or_space(line);
    face_t id = find_face_id(line);
    if (id == -1) {
        update_text(app, speakers, line);
    } else {
        speakers->speaker_id = id;
    }
    sfClock_restart(timer);
    return 0;
}

int dialogue_loop(app_t *app, FILE *stream, sprite_t *background,
    state_t old_state)
{
    sfClock *timer = sfClock_create();
    speakers_t *speakers = init_speakers(app, stream,
        sfRenderWindow_getSize(app->window));
    while (sfRenderWindow_isOpen(app->window) && app->menu->state == dialogue) {
        dialogue_events(app);
        sfRenderWindow_clear(app->window, sfBlack);
        display_game_dialogue(app);
        if (update_dialogue(app, speakers, stream, timer) == 1)
            break;
        display_dialogue(app, background, speakers);
        sfRenderWindow_display(app->window);
    }
    sfClock_destroy(timer);
    return EXIT_SUCCESS;
}

int dialogue_manager(app_t *app, char *filepath)
{
    app->menu->state = dialogue;
    sfRenderWindow_setView(app->window, app->default_view);
    FILE *stream = fopen(filepath, "r");
    if (!stream)
        return EXIT_FAILURE;
    sprite_t *background = create_sprite(COLOR_LAYER);
    scale_sprite(app, background);
    state_t state = app->menu->state;
    app->menu->state = dialogue;
    dialogue_loop(app, stream, background, state);
    destroy_sprite(background);
    app->menu->state = game;
    fclose(stream);
    return EXIT_SUCCESS;
}
