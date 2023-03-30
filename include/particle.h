/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** particle
*/

#include "prototype.h"

#ifndef B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PARTICLE_H
    #define B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PARTICLE_H

    typedef struct particle {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f position;
        int frame;
        int max_frame;
    } particle_t;

#endif //B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_PARTICLE_H
