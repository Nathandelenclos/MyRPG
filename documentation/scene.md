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
