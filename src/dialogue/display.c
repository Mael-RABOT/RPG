/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** display
*/

#include "../../include/prototype.h"

void display_game_dialogue(app_t *app)
{
    display_background(app);
    display_map(app->window, app->maps->selected_map, app->player);
}

static char *find_name(face_t face_id)
{
    switch (face_id) {
        case Player:
            return "#Player";
        case Leonardo:
            return "#Leonardo";
        case Marilyn:
            return "#Marilyn";
    }
    return NULL;
}

static int find_head_pos(speakers_t *speakers)
{
    for (int i = 0; speakers->name_list[i] != NULL; i++) {
        if (my_strcmp(speakers->name_list[i],
            find_name(speakers->speaker_id)) == 0)
            return i;
    }
    return 0;
}

static void display_head(sfRenderWindow *window, speakers_t *speakers)
{
    int pos = find_head_pos(speakers);
    if (pos == -1)
        return;
    sfRenderWindow_drawSprite(window, speakers->face_list[pos]->sprite, NULL);
}

void display_dialogue(app_t *app, sprite_t *background, speakers_t *speakers)
{
    sfRenderWindow_drawSprite(app->window, background->sprite, NULL);
    display_head(app->window, speakers);
    update_cursor(app);
}
