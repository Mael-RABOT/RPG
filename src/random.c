/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** random
*/

#include "../include/prototype.h"

int random_randint(int min, int max)
{
    if (min > max) {
        max ^= min;
        min ^= max;
        max ^= min;
    }
    int result = rand() % ((max + 1) - min) + min;
    return result;
}
