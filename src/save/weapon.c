/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** weapon
*/

#include "../../include/prototype.h"

void write_weapon_infos(FILE *file, weapon_t *weapon)
{
    write_info(file, weapon->damage_point, sfFalse);
    write_info(file, weapon->tier, sfFalse);
    write_info(file, weapon->scaling, sfTrue);
    return;
}
