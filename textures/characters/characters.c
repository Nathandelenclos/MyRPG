/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** characters
*/

#include "../include/rpg.h"

void create_skeleton_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/characters/skeleton.png";
    t->name = "skeleton";
    t->rect = create_rect(384, 320, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_slime_texture(scene *d)
{
    char *slimes[] = {
        "enemy_slime", "green_slime", "pink_slime", "slime", "yellow_slime",
        NULL
    };
    char *filename = NULL;
    for (int i = 0; slimes[i] != NULL; ++i) {
        filename = malloc(sizeof(char) * 37);
        filename[0] = '\0';
        my_strcat(filename, "./assets/characters/");
        my_strcat(filename, slimes[i]);
        my_strcat(filename, ".png");
        put_in_list(&d->textures, create_texture(filename, slimes[i],
            create_rect(224, 160, 0, 0)));
        free(filename);
    }
}

void create_pnj_simon_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/characters/pnj_simon.png";
    t->name = "pnj_simon";
    t->rect = create_rect(288, 35, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_player_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/characters/player.png";
    t->name = "player";
    t->rect = create_rect(288, 240, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_player_mirror_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/characters/player_mirror.png";
    t->name = "player_mirror";
    t->rect = create_rect(288, 240, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_characters_texture(scene *d)
{
    put_in_list(&d->textures, create_texture("./assets/ui/hotbar.jpg", "hotbar",
        create_rect(543, 61, 0, 0)));
    put_in_list(&d->textures, create_texture("./assets/ui/slot_pointer.png", "slot_pointer",
        create_rect(60, 61, 0, 0)));
    create_skeleton_texture(d);
    create_slime_texture(d);
    create_player_texture(d);
    create_pnj_simon_texture(d);
    create_player_mirror_texture(d);
}
