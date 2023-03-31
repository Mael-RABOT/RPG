/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** display
*/

#include "../../include/dante/dante.h"

static int display_line(node_t **line, int line_i,int fd)
{
    int i = 0;
    while (line[i + 1] != NULL) {
        if (line_i == 0 && i == 0) {
            write(fd, "P,", 2);
            i += 1;
            continue;
        }
        if (line[i]->status == CELL)
            write(fd, "-1,", 3);
        else
            write(fd, "20,", 3);
        i += 1;
    }
    if (line[i]->status == CELL)
        write(fd, "-1\n", 3);
    else
       write(fd, "20\n", 3);
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

static int display_first_layer(int x, int y)
{
    int fd = open("./maps/maze/map_1.csv", O_WRONLY | O_CREAT | O_TRUNC);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j += 1) {
            write(fd, "1,", 2);
        }
        write(fd, "1\n", 2);
    }
    close(fd);
    return 0;
}

int display_maze(maze_t *maze)
{
    display_first_layer(maze->size->x, maze->size->y);
    int i = 0;
    int fd = open("./maps/maze/map_2.csv", O_WRONLY | O_CREAT | O_TRUNC);
    while (i < get_len(maze) - 1) {
        display_line(maze->maze[i], i, fd);
        printf("\n");
        i += 1;
    }
    display_line(maze->maze[i], i, fd);
    close(fd);
    return 0;
}