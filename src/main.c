/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** main
*/

#include "../include/prototype.h"

int main(const int ac, const char **av)
{
    srand(time(NULL));
    generator(500, 500, 1);
    return my_rpg(ac, av);
}
