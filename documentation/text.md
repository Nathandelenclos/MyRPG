# Texts
***
## [Structure](../include/struct.h)
```c
typedef struct text_s {
    sfFont *font;
    char *string;
    sfText *text;
    sfVector2f position;
    sfColor color;
    void (*animate)(struct text_s *, scene *d);
} text;
```
***
## Property
### Font
sfFont of CSFML assigned to this text.
```c
sfFont *font;
```
***
### String
The string display in game.
```c
char *string;
```
***
### Text
sfText of CSFML displayed in window.
```c
sfText *text;
```
***
### Position
The Position of text in the [scene](./scene.md).
```c
sfVector2f position;
```
***
### Color
sfColor assigned to this text.
```c
sfColor color;
```
***
## Method
### Screen
Call in [move_manager](../manager/move_manager.c) for animate this text.
```c
void (*animate)(struct text_s *, scene *d);
```
***
## Functions
```c
void text_manager(scene *d);
```
Display all text of the [scene](./scene.md). [here](../manager/text_manager.c)
***
```c
void move_manager(scene *d);
```
Launch animate pointer function for start animation of text. [here](../manager/move_manager.c)
***
```c
text *create_text(char *s, char *string, sfColor color, sfVector2f v);
```
Create text. [here](../manager/text_manager.c)
***
```c
void modify_string(scene *d, char *before, char *after);
```
Modify the string of this text. [here](../manager/text_manager.c)
