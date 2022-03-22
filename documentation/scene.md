# Scene
***
## [Structure](../include/struct.h)
```c
typedef struct scene_s {
    node *objs;
    node *texts;
    node *sounds;
    node *textures;
    state state;
    screen *hub;
    void (*screen)(scene *data);
    void (*event)(scene *data, sfEvent event);
} scene;
```
***
## Property
### Objs
Linked list of [game_obj](./game_obj.md) store in this scene.
```c
node *objs;
```
***
### Texts
Linked list of [texts](./text.md) store in this scene.
```c
node *texts;
```
***
### Sounds
Linked list of sounds store in this scene.
```c
node *sounds;
```
***
### Textures
Linked list of [textures](./texture.md) store in this scene.
```c
node *textures;
```
***
### State
Enum state for identify this scene.
```c
state state;
```
***
### Screen
Main data for all access. [here](./screen.md)
```c
screen *hub;
```
***
## Method
### Screen
Main loop of this scene.
```c
void (*screen)(scene *data);
```
***
### Events
Events of scene this scene.
```c
void (*event)(scene *data, sfEvent event);
```
***
## Functions
```c
void screen_manager(screen *s);
```
load scene. [here](../manager/screen_manager.c)
***
```c
scene *create_scene(screen *s, state state);
```
Create scene with state. [here](../manager/screen_manager.c)
***
```c
scene *get_scene(scene *d, state state);
```
Get another scene with state. [here](../manager/screen_manager.c)
***
```c
void copy_objs(scene *copy, scene *paste, group grp);
```
Copy all object with grp in scene copy to scene paste. [here](../utils/game_obj.c)
***
## Example
For this example I use the [example_scene.c](./example_scene.c) for create an example scene.
```c
void events(scene *d, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(d->hub->window);
    }
}
```
In this function I use a switch case for detect the type of the event, and I wrote the listener of the event.
```c
void start_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}
```
This function is call at all loop of this window.
This function is the main loop of the scene.
```c
void create_data(scene *d)
{
    create_textures(d);
    display_fps(d);
    sound_manager(d);
}
```
In this window I call function for create all element of my scene.
```c
void data_start(screen *screen1)
{
    scene *d = create_scene(screen1, START);
    d->screen = start_screen;
    d->event = events;
    create_data(d);
    put_in_list(&screen1->datas, d);
}
```
In this window I create the structure, and I specify the screen function (start_screen) and the event function (events).
I call create_data for create data at the creation of the scene.
This function is call once of the program at the creation of the window.