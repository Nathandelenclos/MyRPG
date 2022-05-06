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
    text *fps = search_for_n_text(d, "FPS=", 4);
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
        if (event.key.code == sfKeyF3 && fps != NULL) {
            fps->display = !fps->display;
        }
    }
}
