/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** fight.c
*/

#include "../../include/prototype.h"

int fight(app_t *app)
{
    corrupt_map(app);
    sfTime time = sfClock_getElapsedTime(app->fight->clock);
    if (app->fight->is_fighting == 0)
        return 0;
    if (app->fight->fight_tick == 0 && time.microseconds >= 1000000) {
        app->fight->fight_tick = 1;
        trapped_tile(app);
        sfClock_restart(app->fight->clock);
        return 0;
    }
    if (time.microseconds >= 1000000 && app->fight->fight_tick == 1) {
        app->fight->fight_tick = 0;
        kill_player(app);
        restore_tile(app);
        sfClock_restart(app->fight->clock);
        return 0;
    }
    return 0;
}
