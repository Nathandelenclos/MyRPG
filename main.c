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
    srand((unsigned) time(NULL));
    /*sfSprite *sprite = sfSprite_create();
    sfIntRect rect = create_rect(1080, 720, 0, 0);
    sfTexture *t =
        sfTexture_createFromFile("./assets/logo.png", &rect);
    sfSprite_setTexture(sprite, t, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    sfSprite_destroy(sprite);
    sfTexture_destroy(t);*/
    sfVertexArray *a = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(a, sfLines);
    for (int i = 0; i < 100; ++i) {
        sfVertex v;
        v.color = sfBlue;
        v.texCoords = create_vector2f(rand() % 1920, rand() % 1080);
        v.position = v.texCoords;
        sfVertexArray_append(a, v);
        v.position.y += 5;
        sfVertexArray_append(a, v);

    }
    while (1) {
        sfRenderWindow_clear(window, sfBlack);
        for (size_t i = 0; i < sfVertexArray_getVertexCount(a); ++i) {
            sfVertex *v = sfVertexArray_getVertex(a, i);
            v->position.y += 0.08;
            if (v->position.y > 1080) {
                v->position.y = 0;
            }
        }
        sfRenderWindow_drawVertexArray(window, a, NULL);
        sfRenderWindow_display(window);
    }
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
    return hub;
}

int main(int argc, char **argv)
{
    screen *hub = create_hub();
    sfImage *icon = sfImage_createFromFile("./assets/logo.png");
    sfRenderWindow_setIcon(hub->window, sfImage_getSize(icon).x,
        sfImage_getSize(icon).y,
        sfImage_getPixelsPtr(icon));
    //load_screen(hub->window);
    screen_manager(hub);
    start(hub);
    sfImage_destroy(icon);
    //free_game(hub);
    return 0;
}
