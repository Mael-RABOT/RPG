/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player
*/

#include "../prototype.h"

#ifndef B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PLAYER_H
    #define B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PLAYER_H

    typedef struct player {
        int level;
        int hp;
        int stamina;
        int strength;
        int dexterity;
        int defense;
        int experience;
        int level_cost;
    } player_t;

#endif //B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PLAYER_H
