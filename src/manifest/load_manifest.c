/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** load_manifest.c
*/

#include "../../include/prototype.h"

//id:texture_path:collision

static int parse_line(manifest_t **manifest, char *line)
{
    char **array = split(line, ':');
    if (*manifest == NULL) {
        *manifest = create_manifest(my_atoi(array[0]),
            array[1], my_atoi(array[2]));
    } else {
        append_manifest(*manifest, my_atoi(array[0]),
            array[1], my_atoi(array[2]));
    }
    free_array(array);
    return 0;
}

manifest_t *load_manifest(const char *filepath)
{
    manifest_t *manifest = NULL;
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    int read_size = 0;
    getline(&line, &len, fp);
    while ((read_size = getline(&line, &len, fp)) != -1) {
        line[read_size - 1] = '\0';
        parse_line(&manifest, line);
    }
    fclose(fp);
    return manifest;
}
