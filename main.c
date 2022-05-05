/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** main
*/

#include "include/rpg.h"
#include <time.h>

void load_screen(sfRenderWindow *window)
{

}

void start(screen *hub)
{
    scene *scene = hub->datas->data;
    sfEvent event;
    sfRenderWindow_setFramerateLimit(hub->window, 120);
    while (sfRenderWindow_isOpen(hub->window)) {
        scene = get_scene(scene, hub->state);
        sfRenderWindow_clear(hub->window, sfBlack);
        while (sfRenderWindow_pollEvent(hub->window, &event)) {
            scene->event(scene, event);
            event_manager(scene, event);
        }
        scene->screen(scene);
        hub->fps = 1 /
            (sfTime_asMilliseconds(sfClock_restart(hub->clock)) * 0.001);
        sfRenderWindow_display(hub->window);
    }
    sfRenderWindow_destroy(hub->window);
}

screen *create_hub(void)
{
    screen *hub = malloc(sizeof(screen));
    hub->state = START;
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    hub->window = sfRenderWindow_create(mode, "MyRPG", sfFullscreen,
        NULL);
    hub->clock = sfClock_create();
    hub->fps = 0;
    hub->mode = mode;
    hub->datas = NULL;
    hub->s = init_settings_struct();
    return hub;
}

int main(int argc, char **argv)
{
    screen *hub = create_hub();
    sfImage *icon = sfImage_createFromFile("./assets/logo.png");
    sfRenderWindow_setIcon(hub->window, sfImage_getSize(icon).x,
        sfImage_getSize(icon).y,
        sfImage_getPixelsPtr(icon));
    load_screen(hub->window);
    screen_manager(hub);
    start(hub);
    sfImage_destroy(icon);
    destroy_music(hub);
    return 0;
}
