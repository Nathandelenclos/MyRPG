# Screen
***
## [Structure](../include/struct)
```c
typedef struct screen_s {
    sfVideoMode mode;
    state state;
    node *datas;
    sfRenderWindow *window;
    int fps;
    sfClock *clock;
} screen;
```
***
## Property
### Mode
Mode of window with width & height
```c
sfVideoMode mode;
```
***
### State
The [scene](./scene.md) with this state current display
```c
state state;
```
***
### Datas
Linked list with all [scene](./scene.md).
```c
node *datas;
```
***
### Window
sfRenderWindow of CSFML.
```c
sfRenderWindow *window;
```
***
### FPS
Current FPS.
```c
int fps;
```
***
### Clock
main sfClock of game.
```c
sfClock *clock;
```
