/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_text
*/

#include "../../include/prototype.h"

sfText *create_text(sfVector2f position, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(FFFFORWA);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, position);
    return text;
}
