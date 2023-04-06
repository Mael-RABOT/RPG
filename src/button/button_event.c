/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** button_event.c
*/

#include "../../include/prototype.h"

int button_event(button_t *button, sfEvent event)
{
    button_t *tmp_button = button;
    while (tmp_button != NULL) {
        button->is_clicked(button, event.mouseButton);
        button->is_hover(button, event.mouseMove);
        button->is_released(button, event.mouseButton);
        button_event(button->next_button, event);
        tmp_button = tmp_button->next_button;
    }
    return 0;
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
