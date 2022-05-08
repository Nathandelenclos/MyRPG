/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** open_inventory_chest
*/

#include "../include/rpg.h"
#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

int data_null(
    inventory *data, slot_inv *stamp,
    int stamp_i, inventory *stamp_inv
)
{
    if (data == NULL) {
        stamp = NULL;
        stamp_i = -1;
        stamp_inv = NULL;
        return 1;
    }
    return 0;
}

void action_click_on_case(
    scene *d, int i, sfMouseButtonEvent event, inventory *data
)
{
    static slot_inv *stamp = NULL;
    static int stamp_i = -1;
    static inventory *stamp_inv = NULL;
    static inventory_chest_state state = FIRST_CLICK;
    sfVector2f *pos = d->state == CHEST ? init_inventory_pos_places_c()
                                        : init_inventory_pos_places_p();
    if (data_null(data, stamp, stamp_i, stamp_inv)) {
        free(pos);
        state = FIRST_CLICK;
        return;
    }
    if (event.x >= pos[i].x && event.x <= pos[i].x + 140 &&
        event.y >= pos[i].y &&
        event.y <= pos[i].y + 140) {
        if (data->size == 9 && i >= 27)
            i -= 27;
        if (state == FIRST_CLICK) {
            stamp = data->slot[i];
            stamp_i = i;
            stamp_inv = data;
            state = SECOND_CLICK;
        } else {
            stamp_inv->slot[stamp_i] = data->slot[i];
            data->slot[i] = stamp;
            state = FIRST_CLICK;
        }
    }
    free(pos);
}

void data_chest(screen *screen1)
{
    scene *d = create_scene(screen1, CHEST);
    d->screen = chest_screen;
    d->event = events_chest;
    d->active = save_chest_background;
    create_chest_scene_data(d);
    put_in_list(&screen1->datas, d);
}
