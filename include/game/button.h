/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** button
*/

#include "../prototype.h"

#ifndef BUTTON_H_
    #define BUTTON_H_

    typedef struct app app_t;

    typedef enum bool {
        false = 0,
        true
    } bool_t;

    typedef enum button_state {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED,
        GRAYED,
        CHECKED
    } button_state_t;

    typedef struct object_info {
        sfVector2f position;
        sfVector2f scale;
        sfVector2f size;
    } object_info_t;

    typedef struct button {
        sfRectangleShape *rect;
        sfIntRect texture_rect;
        sfTexture *texture;
        int (*is_clicked) (struct button *, sfMouseButtonEvent);
        int (*is_released) (struct button *, sfMouseButtonEvent);
        int (*is_hover) (struct button *, sfMouseMoveEvent);
        void (*action) (struct app *);
        button_state_t state;
        bool_t pressed;
    } button_t;


    button_t *create_button(object_info_t info, void (*action)(app_t *app),
        char *texture_path);
    int load_button_texture(button_t *button, char *pathfile);
    int display_button(sfRenderWindow *window, button_t **button);

    int button_event(app_t *app, button_t **button, sfEvent event);

    int update_buttons_texture(button_t **button);

    int is_button_hover(button_t *button, sfMouseMoveEvent mouse);
    int is_button_released(button_t *button, sfMouseButtonEvent mouse);
    int is_button_clicked(button_t *button, sfMouseButtonEvent mouse);

    int destroy_button(button_t **button);

#endif //BUTTON_H_
