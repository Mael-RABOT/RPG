/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** init_resources
*/

#include "../../include/dante/dante.h"

static int parse_args(int x, int y, maze_t *maze)
{
    if ((maze->size = malloc(sizeof(vector_t))) == NULL)
        return 84;
    maze->size->x = x;
    maze->size->y = y;
    if ((maze->size->x <= 0) || (maze->size->y <= 0))
        return 84;
    return 0;
}

static int create_line(node_t **line, int y, int len)
{
    int x = 0;
    while (x < len) {
        line[x] = malloc(sizeof(node_t));
        line[x]->value = 0;
        line[x]->status = CELL;
        line[x]->position = (vector_t){x, y};
        x += 1;
    }
    line[x] = NULL;
    return 0;
}

static int alloc_maze(maze_t *maze)
{
    if ((maze->maze = malloc(sizeof(node_t **) * (maze->size->y + 1))) == NULL)
        return 84;
    int y = 0;
    while (y < maze->size->y) {
        maze->maze[y] = malloc(sizeof(node_t *) * (maze->size->x + 1));
        create_line(maze->maze[y], y, maze->size->x);
        y += 1;
    }
    maze->maze[y] = NULL;
    return 0;
}

maze_t *init_resources(int x, int y)
{
    maze_t *maze;
    if ((maze = malloc(sizeof(maze_t))) == NULL)
        return NULL;
    if (parse_args(x, y, maze) == 84)
        return NULL;
    if (alloc_maze(maze) == 84)
        return NULL;
    return maze;
}
