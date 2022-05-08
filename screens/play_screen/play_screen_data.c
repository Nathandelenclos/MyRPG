/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/my.h"
#include "../../include/rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>

void play_screen_data(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
    env_manager(data);
}

void play_screen(scene *data)
{
    sfTime time = sfClock_getElapsedTime(data->clock);
    game_obj *p = get_object(data, "player");
    game_obj *map = get_object(data, "maps");
    int seconds = sfTime_asMilliseconds(time) / 1000;
    seconds %= 120;
    sfColor color = sfSprite_getColor(map->sprite);
    play_screen_data(data);
    if (seconds > 20 && seconds < 60)
        get_env(data, RAIN)->active = sfTrue;
    else
        get_env(data, RAIN)->active = sfFalse;
    if (seconds < 40)
        color.a = 100;
    else
        color.a = 255;
    sfSprite_setColor(map->sprite, color);
    p != NULL ? display_chest(data, ((player *) p->data)->inventory) : 0;
}
