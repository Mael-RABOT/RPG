/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_player
*/

#include "../../../include/prototype.h"

player_t *create_player(player_preset_t preset)
{
    player_t *player = malloc(sizeof(player_t));
    player->level = 0;
    player->hp = 5;
    player->stamina = 5;
    player->strength = 5;
    player->dexterity = 5;
    player->defense = 5;
    player->experience = 0;
    player->level_cost = 7;
    return player;
}
