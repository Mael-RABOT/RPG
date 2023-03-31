/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** generator
*/

#include "../../include/dante/dante.h"

static int launch_algo(maze_t *maze)
{
    if (maze->size->x <= 2 || maze->size->y <= 2)
        return 0;
    switch (maze->perfect) {
        case 0:
            recursive_division(maze, (vector_t){0, 0},
                    (vector_t){maze->size->x - 1, maze->size->y - 1}, 0);
            complete_maze(maze);
            break;
        case 1:
            kruskal(maze);
        default:
            break;
    }
    return 0;
}

int generator(int x, int y, int perfect)
{
    maze_t *maze;
    if ((maze = init_resources(x, y)) == NULL)
        return 84;
    maze->perfect = perfect;
    launch_algo(maze);
    display_maze(maze);
    free_resources(maze);
    return 0;
}
