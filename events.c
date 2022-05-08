/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** events
*/

#include "include/my.h"
#include "include/list.h"
#include "include/rpg.h"
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

void draw_debug(scene *d)
{
    text *fps = get_text(d, "fps");
    text *sprite = get_text(d, "entity");
    text *delta = get_text(d, "delta_time");
    if (fps == NULL || sprite == NULL || delta == NULL){
        create_debug(d);
        return draw_debug(d);
    }
    fps->display = fps->display ? 0 : 5;
    sprite->display = sprite->display ? 0 : 5;
    delta->display = delta->display ? 0 : 5;
}

void event_closed(scene *d)
{
    sfRenderWindow_close(d->hub->window);
}

void take_screenshot(scene *d, char *filename)
{
    sfTexture
        *texture = sfTexture_create(d->hub->mode.width, d->hub->mode.height);
    sfTexture_updateFromRenderWindow(texture, d->hub->window, 0, 0);
    sfImage *screenshot = sfTexture_copyToImage(texture);
    sfImage_saveToFile(screenshot, filename);
}

void event_manager(scene *d, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        event_closed(d);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == d->hub->s->c->screen) {
            my_printf(1, "Taking screenshot..");
            take_screenshot(d, "screenshot.png");
            my_printf(1, "(screenshot.png)\n");
        }
        if (event.key.code == d->hub->s->c->info)
            draw_debug(d);
    }
}
