/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** button_creation
*/

#include "../../../include/prototype.h"

void sound_settings(settings_menu_t *settings_menu, object_info_t button_info,
    sfVector2u window_size)
{
    float half = window_size.x / 2;
    float quarter = window_size.x / 4;

    settings_menu->text_sounds = create_sprite(SOUNDS_TITLE);
    settings_menu->sounds = create_sprite(SOUND);

    button_info.size = (sfVector2f){32 * 1.8, 54 * 1.8};
    button_info.position =
    (sfVector2f){half - quarter + TEXT_BUTTON_WIDTH / 2, 420};
    settings_menu->button[0] = create_button(button_info,
        &increase_global_volume, PLUS);

    button_info.position = (sfVector2f){
    half - quarter - TEXT_BUTTON_WIDTH / 2 - button_info.size.x + 2, 420};
    settings_menu->button[1] = create_button(button_info,
        &decrease_global_volume, MINUS);
    return;
}

void music_settings(settings_menu_t *settings_menu, object_info_t button_info,
    sfVector2u window_size)
{
    float half = window_size.x / 2;
    float quarter = window_size.x / 4;

    button_info.size = (sfVector2f){32 * 1.8, 54 * 1.8};
    button_info.position =
        (sfVector2f){half - quarter + TEXT_BUTTON_WIDTH / 2, 620};

    settings_menu->music = create_sprite(MUSIC);
    button_info.position =
    (sfVector2f){half - quarter + TEXT_BUTTON_WIDTH / 2, 610};
    settings_menu->button[2] = create_button(button_info,
        &increase_music_volume, PLUS);

    button_info.position = (sfVector2f){
    half - quarter - TEXT_BUTTON_WIDTH / 2 - button_info.size.x + 2, 610};
    settings_menu->button[3] = create_button(button_info,
        &decrease_music_volume, MINUS);
    return;
}

void resolution_bis(settings_menu_t *settings_menu, object_info_t button_info,
    sfVector2u window_size)
{
    float half = window_size.x / 2;
    float quarter = window_size.x / 4;

    button_info.size = (sfVector2f){261 / 3 * 2.9, 32 * 2.9};
    button_info.position =
        (sfVector2f){half + quarter - 372 / 4 * 2.9 / 2 - 160, 610};
    settings_menu->button[7] = create_button(button_info, &set_800_400,
        LOW_RESOLUTION);

    button_info.position =
        (sfVector2f){half + quarter - 372 / 4 * 2.9 / 2 + 190, 610};
    settings_menu->button[8] = create_button(button_info, &set_1920_1080,
        HIGH_RESOLUTION);

    settings_menu->button[9] = NULL;
}

void resolution_settings(settings_menu_t *settings_menu,
    object_info_t button_info, sfVector2u window_size)
{
    float half = window_size.x / 2;
    float quarter = window_size.x / 4;
    settings_menu->text_resolution = create_sprite(RESOLUTION_TITLE);

    button_info.size = (sfVector2f){372 / 4 * 2.9, 32 * 2.9};
    button_info.position =
    (sfVector2f){half + quarter - 372 / 4 * 2.9 / 2 - 160, 420};
    settings_menu->button[4] = create_button(button_info, &toggle_fullscreen,
        FULLSCREEN);
    button_info.position =
    (sfVector2f){half + quarter - 372 / 4 * 2.9 / 2 + 190, 420};
    settings_menu->button[5] = create_button(button_info, &toggle_windowed,
        WINDOWED);
    button_info.position =
    (sfVector2f){half + quarter - 372 / 4 * 2.9 / 2, 320};
    settings_menu->button[6] = create_button(button_info, &toggle_borderless,
        BORDERLESS);
    resolution_bis(settings_menu, button_info, window_size);
}
