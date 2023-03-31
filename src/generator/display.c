/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** display
*/

#include "../../include/dante/dante.h"

static int display_line(node_t **line)
{
    int i = 0;
    while (line[i + 1] != NULL) {
        if (line[i]->status == CELL)
            printf("*,");
        else
            printf("1,");
        i += 1;
    }
    if (line[i]->status == CELL)
        printf("*");
    else
       printf("1");
    return 0;
}

static int get_len(maze_t *maze)
{
    int len = 0;
    while (maze->maze[len] != NULL) {
        len += 1;
    }
    return len;
}

int display_maze(maze_t *maze)
{
    int i = 0;
    while (i < get_len(maze) - 1) {
        display_line(maze->maze[i]);
        printf("\n");
        i += 1;
    }
    display_line(maze->maze[i]);
    return 0;
}
