/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** life bar utils
*/

#include "../include/my.h"
#include "../include/rpg.h"
#include <SFML/Window.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>

life_bar *create_life_bar(
    int width, int height, sfColor main_color, sfColor back_color
)
{
    life_bar *lb = malloc(sizeof(life_bar));
    lb->rect = create_rect(width, height, 0, 0);
    lb->image = sfImage_createFromColor(width, height, main_color);
    lb->sprite = sfSprite_create();
    lb->texture = sfTexture_createFromImage(lb->image, &lb->rect);
    lb->main_color = main_color;
    lb->back_color = back_color;
    sfSprite_setTexture(lb->sprite, lb->texture, sfTrue);
    sfSprite_setTextureRect(lb->sprite, lb->rect);
    return lb;
}

void life_percent(life_bar *lb, float percent)
{
    if (percent <= 0) {
        sfImage_destroy(lb->image);
        lb->image = sfImage_createFromColor(lb->rect.width, lb->rect.height,
            lb->back_color);
    }
    sfImage_destroy(lb->image);
    lb->image = sfImage_createFromColor
    (lb->rect.width, lb->rect.height, lb->main_color);
    int u = ceilf(lb->rect.width / 100);
    // for (int i = 0; i < u * lb->rect.height && percent > 0; i++)
    //     for (int j = 0; j < 5; j++) {
    //         sfImage_setPixel(lb->image, i, j,
    //             lb->main_color);
    //     }
    for (int i = u * percent; i < lb->rect.width && percent > 0; i++)
        for (int j = 0; j < lb->rect.height; j++) {
            sfImage_setPixel(lb->image, i, j,
                lb->back_color);
        }
    sfTexture_destroy(lb->texture);
    lb->texture = sfTexture_createFromImage(lb->image, &lb->rect);
    sfSprite_setTexture(lb->sprite, lb->texture, sfTrue);
}

void print_life_bar(scene *d, life_bar *lb, float percent, sfVector2f pos)
{
    if (lb == NULL)
        return;
    life_percent(lb, percent);
    sfSprite_setPosition(lb->sprite, pos);
    sfRenderWindow_drawSprite(d->hub->window, lb->sprite, NULL);
}