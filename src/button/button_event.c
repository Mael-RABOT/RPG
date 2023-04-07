/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** button_event.c
*/

#include "../../include/prototype.h"

int button_event(button_t **button, sfEvent event)
{
    int i = 0;
    while (button[i] != NULL) {
        if (event.type == sfEvtMouseMoved)
            button[i]->is_hover(button[i], event.mouseMove);
        if (event.type == sfEvtMouseButtonPressed)
            button[i]->is_clicked(button[i] , event.mouseButton);
        if (event.type == sfEvtMouseButtonReleased)
            button[i]->is_released(button[i], event.mouseButton);
        i += 1;
    }
    return 0;
}

int update_texture(button_t **button, app_t *app)
{
    int i = 0;
    while (button[i] != NULL) {
        if (button[i]->state == RELEASED) {
            button[i]->action(app);
            button[i]->state = NONE;
        }
        i += 1;
    }
    return 0;
}
