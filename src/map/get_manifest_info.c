/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** get_manifest_info.c
*/

#include "../../include/prototype.h"

int count_manifest_layer(const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    size_t count = 0;
    size_t len = 0;
    size_t read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        if (my_strncmp(line, "layer", 5) == 0)
            count += 1;
    }
    free(line);
    return count;
}

int count_manifest_object(const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    size_t count = 0;
    size_t len = 0;
    size_t read_size = 0;
    while ((read_size = getline(&line, &len, fp)) != -1) {
        if (my_strncmp(line, "layer", 5) == 0)
            continue;
        count += 1;
    }
    free(line);
    return count;
}