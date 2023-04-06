/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** choose_save
*/

#include "../../include/prototype.h"

int save_exist(char *pathfile)
{
    FILE *file = fopen(pathfile, "r");

    if (file != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

int choose_save(void)
{
    if (save_exist("save/savegame_1") == 0)
        return 1;
    if (save_exist("save/savegame_2") == 0)
        return 2;
    if (save_exist("save/savegame_3") == 0)
        return 3;
    return 1;
}
