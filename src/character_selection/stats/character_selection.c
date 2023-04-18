/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** character_selection
*/

#include "../../../include/prototype.h"

static void event_character(app_t *app, button_t **button_list)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        button_event(app, button_list, event);
    }
}

static button_t **init_character_stats_buttons(void)
{
    button_t **list = malloc(sizeof(button_t) * 4);
    object_info_t info = (object_info_t){(sfVector2f){428.0f, 682.0f
    },(sfVector2f){1.0f, 1.0f
    },(sfVector2f){294.0f, 89.0f
    }};
    list[0] = create_button(info, &stat_strength_button, STAT_STRENGTH);
    info = (object_info_t){(sfVector2f){817.0f, 682.0f
    },(sfVector2f){1.0f, 1.0f
    },(sfVector2f){336.0f, 89.0f
    }};
    list[1] = create_button(info, &stat_dexterity_button, STAT_DEXTERITY);
    info = (object_info_t){(sfVector2f){1238.0f, 682.0f
    },(sfVector2f){1.0f, 1.0f
    },(sfVector2f){294.0f, 89.0f
    }};
    list[2] = create_button(info, &stat_default_button, STAT_DEFAULT);
    list[3] = NULL;
    return list;
}

static void display_character_stats(app_t *app, sprite_t *background,
    button_t **button_list)
{
    sfRenderWindow_drawSprite(app->window, background->sprite, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawRectangleShape(app->window,
            button_list[i]->rect, NULL);
    update_cursor(app);
}

void character_selection(app_t *app)
{
    app->menu->state = character_stat_selection;
    sprite_t *background =
        create_sprite("./assets/backgrounds/character_stats.png");
    button_t **button_list = init_character_stats_buttons();

    while (sfRenderWindow_isOpen(app->window)
        && app->menu->state == character_stat_selection) {
        event_character(app, button_list);
        sfRenderWindow_clear(app->window, sfBlack);
        display_character_stats(app, background,button_list);
        sfRenderWindow_display(app->window);
    }
}
