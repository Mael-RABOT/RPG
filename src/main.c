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
    generator(50, 50, 1);
    return my_rpg(ac, av);
}
