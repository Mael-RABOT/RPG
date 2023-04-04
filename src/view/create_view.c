/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_view.c
*/

#include "../../include/prototype.h"

sfView *create_view(sfVector2f size)
{
    sfView *view = sfView_create();
    sfView_setSize(view, size);
    return view;
}
