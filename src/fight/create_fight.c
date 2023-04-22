/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_fight.c
*/

#include "../../include/prototype.h"

int destroy_fight(fight_t *fight)
{
    sfClock_destroy(fight->clock);
    free(fight);
    return 0;
}

fight_t *create_fight(void)
{
    fight_t *fight = malloc(sizeof(fight_t));
    fight->is_fighting = 0;
    fight->fight_tick = 0;
    fight->clock = sfClock_create();
    return fight;
}
