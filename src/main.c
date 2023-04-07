/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** main
*/

#include "../include/prototype.h"

static int display_help(void)
{
    FILE *stream = fopen("./help", "r");
    if (!stream)
        return 1;
    size_t len;
    char *line = NULL;
    while (getline(&line, &len, stream) != -1)
        my_printf(line);
    fclose(stream);
    free(line);
    return 0;
}

static int parsing(const int ac, const char **av)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-h") == 0)
            return display_help();
    }
    return -1;
}

int main(const int ac, const char **av)
{
    int parsing_value = parsing(ac, av);
    if (parsing_value != -1)
        return (parsing_value);
    srand(time(NULL));
    return my_rpg(ac, av);
}
