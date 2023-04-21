/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player_event.c
*/

#include "../../include/prototype.h"

static int detect_move_clock(app_t *app)
{
    sfTime time = sfClock_getElapsedTime(app->player->move_clock);
    if (time.microseconds < 1000 || app->menu->state != game)
        return 0;
    sfClock_restart(app->player->move_clock);
    return 1;
}

int move_player(app_t *app, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && detect_move_clock(app) == 1) {
        int code = event.key.code;
        switch (code) {
            case 25:
                move_top(app, app->maps, app->player, app->view);
                break;
            case 18:
                move_bot(app, app->maps, app->player, app->view);
                break;
            case 16:
                move_left(app, app->maps, app->player, app->view);
                break;
            case 3:
                move_right(app, app->maps, app->player, app->view);
                break;
            default:
                break;
        }
    }
    return 0;
}
