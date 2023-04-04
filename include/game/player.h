/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player
*/

#include "../prototype.h"

#ifndef B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PLAYER_H
    #define B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PLAYER_H

    typedef struct weapon {
        int damage_point;
        weapon_tier tier;
        scaling_t scaling;
    } weapon_t;

    typedef struct player {
        sfBool alive;
        int level;
        int hp;
        int stamina;
        int strength;
        int dexterity;
        int defense;
        int experience;
        int level_cost;
        weapon_t *weapon;
    } player_t;

#endif //B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PLAYER_H
