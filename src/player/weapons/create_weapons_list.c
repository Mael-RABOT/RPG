/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_weapons
*/

#include "../../../include/prototype.h"

static int count_elements(void)
{
    FILE *stream = fopen("./assets/items/weapons/manifest", "r");
    if (!stream)
        return 0;
    size_t len;
    char *line = NULL;
    int i = 0;
    while (getline(&line, &len, stream) != -1)
        i++;
    fclose(stream);
    return i;
}

static void add_weapons(app_t *app, char **args)
{
    app->weapons_list[app->weapons_count] = malloc(sizeof(weapon_t));
    app->weapons_list[app->weapons_count]->sprite
        = create_sprite(args[weapons_filepath]);
    app->weapons_list[app->weapons_count]->damage_point
        = my_atoi(args[weapons_damage]);
    app->weapons_list[app->weapons_count]->scaling
        = my_atoi(args[weapons_scaling]);
    app->weapons_list[app->weapons_count]->tier
        = my_atoi(args[weapons_tier]);
    app->weapons_count += 1;
}

void create_weapons_list(app_t *app)
{
    FILE *stream = fopen("./assets/items/weapons/manifest", "r");
    if (!stream)
        return;
    app->weapons_list = malloc(sizeof(weapon_t*) * (count_elements()));
    size_t len;
    char *line = NULL;
    char **args;
    app->weapons_count = 0;
    if (getline(&line, &len, stream) == -1)
        return;
    while (getline(&line, &len, stream) != -1) {
        remove_trailing_newline_or_space(line);
        args = split(line, ':');
        add_weapons(app, args);
    }
    free(line);
    fclose(stream);
}
