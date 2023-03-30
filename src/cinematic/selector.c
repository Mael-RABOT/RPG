/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** selector
*/

#include "../../include/prototype.h"

char *get_cinematic_path(cinematic_t cinematic_type)
{
    switch (cinematic_type) {
        case Tutorial_door:
            return TUTORIAL_DOOR;
        case Death:
            return DEATH_SCREEN;
    }
    return NULL;
}

int find_max_frame(cinematic_t cinematic_type)
{
    switch (cinematic_type) {
        case Tutorial_door:
            return TUTORIAL_FRAME;
        case Death:
            return DEATH_FRAME;
    }
    return -1;
}
