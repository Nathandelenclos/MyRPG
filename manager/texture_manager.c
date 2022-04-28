/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** Manager
*/

#include "../include/rpg.h"

texture *create_texture(char *filename, char *name, sfIntRect rect)
{
    texture *t = malloc(sizeof(texture));
    t->filename = filename;
    t->name = name;
    t->rect = rect;
    if (filename != NULL)
        t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    return t;
}

texture *get_texture(scene *d, char *name)
{
    texture *t;
    node *tmp = d->textures;
    if (name == NULL)
        return NULL;
    while (tmp != NULL) {
        t = (texture *)tmp->data;
        if (my_strcmp(t->name, name))
            return t;
        tmp = tmp->next;
    }
    return NULL;
}

void create_textures(scene *d)
{
    create_buttons_texture(d);
    create_characters_texture(d);
    create_chest_and_obj_texture(d);
    create_particles_texture(d);
    create_walls_texture(d);
    create_tilesets_texture(d);
    create_banners_texture(d);
    create_controls_texture(d);
    create_icon_questionmark_texture(d);
    create_icon_ranking_texture(d);
    create_icon_settings_texture(d);
    create_icon_triangle_texture(d);
    create_icon_trophy_texture(d);
    create_icon_twitter_texture(d);
    create_icon_watchad_texture(d);
    create_icon_youtube_texture(d);
    create_menu_texture(d);
    create_icons_texture(d);
    create_chest_inventory_texture(d);
}
