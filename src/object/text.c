/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** text.c
*/

#include "../../include/prototype.h"

text_t *create_text(const char *pathfile, int size, sfColor color, char *texts)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile(pathfile);
    text->text = sfText_create();

    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, size);
    sfText_setFillColor(text->text, color);
    sfText_setString(text->text, texts);
    return text;
}
