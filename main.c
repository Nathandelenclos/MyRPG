/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** main
*/

#include "include/rpg.h"
#include <time.h>

void load_screen(sfRenderWindow *window, sfVideoMode mode)
{
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect = create_rect(600, 450, 0, 0);
    sfTexture *t = sfTexture_createFromFile("./assets/ui/menu_sprites.png", &rect);
    sfSprite_setTexture(sprite, t, sfTrue);
    sfSprite_setPosition(sprite, create_vector2f(0, -50));
    sfSprite_setScale(sprite, create_vector2f(mode.width / 600.0, mode.width / 600.0));
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

void start(screen *hub)
{
    scene *scene = hub->datas->data;
    sfEvent event;
    sfRenderWindow_setFramerateLimit(hub->window, 120);
    while (sfRenderWindow_isOpen(hub->window)) {
        scene = get_scene(scene, hub->state);
        sfRenderWindow_clear(hub->window, sfBlack);
        scene->screen(scene);
        while (sfRenderWindow_pollEvent(hub->window, &event)) {
            scene->event(scene, event);
            event_manager(scene, event);
        }
        sfTime dtime = sfClock_restart(hub->clock);
        hub->delta_time = sfTime_asMilliseconds(dtime);
        hub->fps = 1 /
            (sfTime_asMilliseconds(dtime) * 0.001);
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
    load_screen(hub->window, hub->mode);
    screen_manager(hub);
    start(hub);
    destroy_music(hub);
    sfImage_destroy(icon);
    return 0;
}
