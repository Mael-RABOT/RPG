/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** display
*/

#include "../../include/dante/dante.h"

static int display_first_line(int fd, maze_t *maze)
{
    int i = 0;
    while (maze->maze[0][i] != NULL) {
        write(fd, "20,", 3);
        i += 1;
    }
    write(fd, "20\n", 3);
    return 0;
}

static int display_cell(int fd, int is_end, int status)
{
    if (is_end == 0) {
        if (status == CELL)
            write(fd, "-1,", 3);
        else
            write(fd, "20,", 3);
    } else {
        if (status == CELL)
            write(fd, "-1\n", 3);
        else
            write(fd, "20\n", 3);
    }
    return 0;
}

static int display_line(node_t **line, int line_i, int fd, int is_end)
{
    int i = 0;
    while (line[i + 1] != NULL) {
        if (i == 0)
            write(fd, "20,", 3);
        if (i == 0 && line_i == 0) {
            write(fd, "67,", 3);
            i += 1;
            continue;
        }
        display_cell(fd, 0, line[i]->status);
        i += 1;
    }
    if (is_end == 1)
        write(fd, "66\n", 3);
    else
        display_cell(fd, 1, line[i]->status);
    return 0;
}

int display_maze(maze_t *maze)
{
    display_first_layer(maze->size->x, maze->size->y);
    int i = 0;
    int fd = open("./maps/Maze/map_2.csv", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    display_first_line(fd, maze);
    while (maze->maze[i] != NULL) {
        display_line(maze->maze[i], i, fd, maze->maze[i + 1] == NULL);
        i += 1;
    }
    close(fd);
    return 0;
}
