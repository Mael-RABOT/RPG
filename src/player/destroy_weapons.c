/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_weapons.c
*/

#include "../../include/prototype.h"

static int destroy_weapon(weapon_t *weapon)
{
    destroy_sprite(weapon->sprite);
    free(weapon);
    return 0;
}

int destroy_weapons(weapon_t **weapons)
{
    int i = 0;
    while (weapons[i] != NULL) {
        destroy_weapon(weapons[i]);
        i += 1;
    }
    free(weapons);
    return 0;
}
