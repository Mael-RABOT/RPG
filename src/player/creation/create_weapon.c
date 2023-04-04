/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_weapon
*/

#include "../../../include/prototype.h"

static void make_saber(weapon_t *weapon)
{
    weapon->damage_point = 3;
    weapon->scaling = Scale_Dexterity;
    weapon->tier = Good;
}

static void make_bat(weapon_t *weapon)
{
    weapon->damage_point = 2;
    weapon->scaling = Scale_Strength;
    weapon->tier = Normal;
}

static void make_sword(weapon_t *weapon)
{
    weapon->damage_point = 2;
    weapon->scaling = Scale_Strength;
    weapon->tier = Normal;
}

static void make_fist(weapon_t *weapon)
{
    weapon->damage_point = 1;
    weapon->scaling = None;
    weapon->tier = Bad;
}

weapon_t *create_weapon(weapon_type_t type)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));
    if (type == Fist)
        make_fist(weapon);
    if (type == Sword)
        make_sword(weapon);
    if (type == Bat)
        make_bat(weapon);
    if (type == Saber)
        make_saber(weapon);
    return weapon;
}
