/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** display_first_layer.c
*/


#include "../../include/dante/dante.h"

int display_first_layer(int x, int y)
{
    int fd = open("./maps/Maze/map_1.csv", O_WRONLY | O_CREAT | O_TRUNC);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= x; j += 1) {
            write(fd, "-1,", 3);
        }
        write(fd, "-1\n", 3);
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j <= x; j += 1) {
            write(fd, "1,", 2);
        }
        write(fd, "1\n", 2);
    }
    close(fd);
    return 0;
}

