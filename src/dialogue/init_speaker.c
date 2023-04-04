/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** init_speaker
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
        if (i == 0)
            speakers->speaker_id = face_id;
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
    speakers->name_list = split(line, ':');
    free(line);
    int arr_size = len_array(
        speakers->name_list);
    speakers->face_list = malloc(sizeof(sprite_t) * arr_size + 1);
    fill_speaker(speakers,
        speakers->name_list, size);
    return speakers;
}
