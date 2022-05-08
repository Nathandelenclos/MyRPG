/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** chest_and_obj
*/

#include "../include/rpg.h"

void create_chest1_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/objects/chest_01.png";
    t->name = "basic_chest";
    t->rect = create_rect(64, 16, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_chest2_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/objects/chest_02.png";
    t->name = "golden_chest";
    t->rect = create_rect(64, 16, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_objects_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/objects/objects.png";
    t->name = "objects";
    t->rect = create_rect(256, 208, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_chest_and_obj_texture(scene *d)
{
    create_chest1_texture(d);
    create_chest2_texture(d);
    create_objects_texture(d);
    put_in_list(&d->textures,
        create_texture("./assets/objects/apples.png", "apple",
            create_simple_rect(25, 15)));
    //    create_bed_texture(d);
}
