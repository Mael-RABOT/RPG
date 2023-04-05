/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** attack
*/

#include "../../include/prototype.h"

int calcul_damage(stat_t *player)
{
    switch (player->weapon->scaling) {
        case None:
            return player->weapon->damage_point + 1;
        case Scale_Strength:
            return player->weapon->damage_point
        + player->weapon->damage_point * (int)(player->strength / 5) + 1;
        case Scale_Dexterity:
            return player->weapon->damage_point
        + player->weapon->damage_point * (int)(player->dexterity / 5) + 1;
    }
    return 0;
}

int calcul_damage_taken(stat_t *player, int damage)
{
    return (int)(damage - (player->defense / 5));
}

void attack(stat_t *attacker, stat_t *defender)
{
    int damage = calcul_damage(attacker);
    int damage_taken = calcul_damage_taken(defender, damage);
    if (damage_taken == 0)
        ++damage_taken;
    defender->hp -= damage_taken;
    if (defender->hp <= 0)
        defender->alive = sfFalse;
}
