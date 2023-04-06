/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_player
*/

#include "../../../include/prototype.h"

static void apply_strength(stat_t *player)
{
    player->level = 5;
    player->hp = 7;
    player->stamina = 6;
    player->strength = 9;
    player->dexterity = 3;
    player->defense = 5;
    player->experience = 0;
}

static void apply_dexterity(stat_t *player)
{
    player->level = 5;
    player->hp = 7;
    player->stamina = 4;
    player->strength = 4;
    player->dexterity = 12;
    player->defense = 2;
    player->experience = 0;
}

static void apply_default(stat_t *player)
{
    player->level = 0;
    player->hp = 5;
    player->stamina = 5;
    player->strength = 5;
    player->dexterity = 5;
    player->defense = 5;
    player->experience = 0;
}

stat_t *create_player(player_preset_t preset, weapon_type_t type)
{
    stat_t *player = malloc(sizeof(stat_t));
    switch (preset) {
        case Strength:
            apply_strength(player); break;
        case Dexterity:
            apply_dexterity(player); break;
        default:
            apply_default(player); break;
    }
    set_level_cost(player);
    player->weapon = create_weapon(type);
    player->alive = sfTrue;
    return player;
}
