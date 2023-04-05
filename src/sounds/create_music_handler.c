/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_music_handlere
*/

#include "../../include/prototype.h"

static int preshot_song_number(void)
{
    FILE *stream = fopen(SOUND_MANIFEST, "r");
    if (!stream)
        return 0;
    size_t len;
    char *line = NULL;
    if (getline(&line, &len, stream) == -1)
        return 0;
    int count = 0;
    while (getline(&line, &len, stream) != -1)
        ++count;
    fclose(stream);
    return count;
}

static void init_handler(app_t *app)
{
    int found_elements = preshot_song_number();
    app->music_handler = malloc(sizeof(music_t));
    app->music_handler->song_number = 0;
    app->music_handler->songs = malloc(sizeof(song_t *) * found_elements);
}

static song_t *create_song(char **args)
{
    song_t *song = malloc(sizeof(song_t));
    song->id = my_atoi(args[0]);
    song->path = malloc(sizeof(char) * (my_strlen(args[1]) + 1));
    my_strcpy(song->path, args[1]);
    song->type = my_atoi(args[2]);
    return song;
}

static void add_song(app_t *app, char *line)
{
    if (!line)
        return;
    char **args = split(line, ':');
    app->music_handler->songs[app->music_handler->song_number]
        = create_song(args);
    app->music_handler->song_number += 1;
    free_array(args);
}

void create_music_handler(app_t *app)
{
    FILE *stream = fopen(SOUND_MANIFEST, "r");
    if (!stream)
        return;
    size_t len;
    char *line = NULL;
    if (getline(&line, &len, stream) == -1)
        return;
    init_handler(app);
    while (getline(&line, &len, stream) != -1) {
        remove_trailing_newline_or_space(line);
        add_song(app, line);
    }
    free(line);
    fclose(stream);
}
