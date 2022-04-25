# Game object
***
## [Structure](../include/struct.h)
```c
typedef struct game_obj_s {
    type type;
    void *data;
    group grp;
    sfSprite *sprite;
    texture *texture;
    sfIntRect rect;
    sfVector2f position;
    int display;
    char *name;
    void (*action)(game_obj *, scene *);
    void (*animate)(scene *, game_obj *);
    sfClock *clock;
    sfVector2f vector;
} game_obj;
```
***
## Property
### Type
Enum type qui permet de savoir quoi cast `void *data`.
```c
type type;
```
***
### data
void * cast celon ce qu'il y à dans `type type;` (structure & type & etc...)
```c
void *data;
```
***
### Group
Enum group, qui permet d'identifier quel type d'objet c'est. exemple: ennemie, PNG, map, ...
```c
group grp;
```
***
### Sprite
Sprite of CSFML.
```c
sfSprite *sprite;
```
***
### Texture
Structure texture qui est affecter au sprite.
```c
texture *texture;
```
***
### Rect
SfIntRect de CSFML qui est le rect du sprite.
```c
sfIntRect rect;
```
***
### Position
Position du sprite actuellement.
```c
sfVector2f position;
```
***
### Display
Priority of display. (0 => no display)
```c
int display;
```
***
### Name
Name of object for identify.
```c
char *name;
```
### Clock
sfClock of object. CSFML.
```c
sfClock *clock;
```
***
### Vector
Vector for move object on window.
```c
sfVector2f vector;
```
***
## Method
### Action
Call at [sprite_manager](../manager/sprites_manager.c) for display object
```c
void (*action)(game_obj *, scene *);
```
***
### Animate
Call at [time_manager](../manager/time_manager.c) for animate sprite. 
```c
void (*animate)(scene *, game_obj *);
```
***
## Functions
```c
void sprites_manager(scene *d);
```
Display all object. [here](../manager/sprites_manager.c)
***
```c
game_obj *create_obj(
    scene *d, char *texture_name, sfIntRect rect, sfVector2f *vector
);
```
create game object. [here](../utils/game_obj.c)
***
```c
void move_manager(scene *d);
```
Launch action pointer function for start action of object. [here](../manager/move_manager.c)
***
```c
void copy_objs(scene *copy, scene *paste, group grp);
```
Copy all object with grp in scene copy to scene paste. [here](../utils/game_obj.c)
