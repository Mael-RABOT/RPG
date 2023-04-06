/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** button_event.c
*/

#include "../../include/prototype.h"

int button_event(button_t *button, sfMouseButtonEvent event)
{
    if (button == NULL) {
        return 0;
    } else {
        button->is_clicked(button, event);
        return button_event(button->next_button, event);
    }
}

int update_texture(button_t *button, app_t *app)
{
    if (button == NULL) {
        return 0;
    } else {
        if (button->state == RELEASED) {
            button->action(app);
        }
        return update_texture(button->next_button, app);
    }
}
