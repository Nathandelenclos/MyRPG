/*
** EPITECH PROJECT, 2021
** MyRPG - Player particle
** File description:
** player particle functions
*/

#include "../../include/rpg.h"

void animate_particle(scene *s, particle *p)
{
    game_obj *d = get_object(s, "player");
    player *f = (player *)d->data;
    sfIntRect r = sfSprite_getTextureRect(p->sprite);

    if (r.left > (16 * 2)) {
        put_in_list(&f->particles, create_particle(s));
        return;
    }
    r.left += r.width;
    sfSprite_setTextureRect(p->sprite, r);
    p->state++;
}

void animate_all_particles(scene *s, player *p)
{
    node *tmp = p->particles;
    particle *par = NULL;
    while (tmp != NULL) {
        par = (particle *)tmp->data;
        par->animate(s, par);
        tmp = tmp->next;
    }
}

particle *create_particle(scene *d)
{
    particle *p = malloc(sizeof(particle));
    game_obj *g = get_object(d, "player");
    sfVector2f v = sfSprite_getPosition(g->sprite);

    v.y += g->rect.height * sfSprite_getScale(g->sprite).y;
    p->texture = get_texture(d, "particle")->texture;
    p->sprite = sfSprite_create();
    p->state = 0;
    p->animate = animate_particle;
    set_scale(d, p->sprite, 10);
    sfSprite_setPosition(p->sprite, v);
    sfSprite_setTexture(p->sprite, p->texture, sfTrue);
    sfSprite_setTextureRect(p->sprite, create_simple_rect(16,12));
    return p;
}