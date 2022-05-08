/*
** EPITECH PROJECT, 2021
** other_texture_part_one.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../../include/rpg.h"

void create_other_things_texture(scene *d)
{
    put_in_list(&d->textures, create_texture(
        "./assets/ui/others/coin.png",
        "coin", create_rect(8, 8, 0, 0)));
    put_in_list(&d->textures, create_texture(
        "./assets/ui/others/diamond.png",
        "diamond", create_rect(8, 8, 0, 0)));
    put_in_list(&d->textures, create_texture(
        "./assets/ui/others/scrollbar.png",
        "scrollbar", create_rect(8, 43, 0, 0)));
    put_in_list(&d->textures, create_texture(
        "./assets/ui/others/star.png",
        "star", create_rect(20, 20, 0, 0)));
    put_in_list(&d->textures, create_texture(
        "./assets/ui/others/wreath.png",
        "wreath", create_rect(17, 11, 0, 0)));
}

void create_gold_things_texture(scene *d)
{
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/currency_bar_gold.png",
            "currency_bar_gold", create_rect(58, 17, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/gold_handle.png",
            "gold_handle", create_rect(8, 10, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/gold_minus.png",
            "gold_minus", create_rect(7, 2, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/gold_plus.png",
            "gold_plus", create_rect(7, 6, 0, 0)));
}

void create_silver_things_texture(scene *d)
{
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/currency_bar_silver.png",
            "currency_bar_silver", create_rect(58, 17, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/silver_handle.png",
            "silver_handle", create_rect(8, 10, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/silver_minus.png",
            "silver_minus", create_rect(7, 2, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/silver_plus.png",
            "silver_plus", create_rect(7, 6, 0, 0)));
}

void create_toggle_texture(scene *d)
{
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/toggle_gold_on.png",
            "toggle_gold_on", create_rect(30, 15, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/toggle_gold_off.png",
            "toggle_gold_off", create_rect(30, 15, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/toggle_silver_on.png",
            "toggle_silver_on", create_rect(30, 15, 0, 0)));
    put_in_list(&d->textures,
        create_texture("./assets/ui/others/toggle_silver_off.png",
            "toggle_silver_off", create_rect(30, 15, 0, 0)));
}

void create_others_texture(scene *d)
{
    create_other_things_texture(d);
    create_gold_things_texture(d);
    create_silver_things_texture(d);
    create_toggle_texture(d);
}
