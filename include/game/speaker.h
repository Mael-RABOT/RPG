/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** speaker
*/

#include "../prototype.h"

#ifndef B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_SPEAKER_H
    #define B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_SPEAKER_H

    typedef struct speakers {
        sprite_t **face_list;
        char **name_list;
        face_t speaker_id;
    } speakers_t;

#endif //B_MUL_200_LYN_2_1_MYRPG_MATHIEU_BOREL_SPEAKER_H
