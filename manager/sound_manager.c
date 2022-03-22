/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Manager
*/

#include "../include/rpg.h"

sound *create_sound(char *filename, enum sound_grp grp, float volume)
{
    sound *s = malloc(sizeof(sound));
    s->music = sfMusic_createFromFile(filename);
    sfMusic_setVolume(s->music, volume);
    s->grp = grp;
    return s;
}

void play_sound(scene *d, enum sound_grp grp)
{
    node *tmp = d->sounds;
    sound *m;
    while (tmp != NULL) {
        m = (sound *)tmp->data;
        if (m->grp == grp)
            sfMusic_play(m->music);
        tmp = tmp->next;
    }
}

void sound_manager(scene *d)
{
    //sound *music = create_sound("./assets/soundtrack.wav", MUSIC, 25);
    //put_in_list(&d->sounds, music);

    //sfMusic_setLoop(music->music, sfTrue);
    //sfMusic_play(music->music);
}

void destroy_music(screen *hub)
{
    scene *d;
    node *tmp = hub->datas;
    node *tmp_d;
    sound *t;
    while (tmp != NULL) {
        d = (scene *)tmp->data;
        if (d != NULL)
            tmp_d = d->sounds;
        while (tmp_d != NULL) {
            t = (sound *)tmp_d->data;
            sfMusic_destroy(t->music);
            tmp_d = tmp_d->next;
        }
        tmp = tmp->next;
    }
}
