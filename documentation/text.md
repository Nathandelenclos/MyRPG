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
## Example
For this example I use the [fps.c](./fps.c) for create an example text.
```c
void animate_fps(text *t, scene *d)
{
    char *points = my_int_to_str(d->hub->fps);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "FPS: ");
    my_strcat(points_s, points);
    modify_string(d, t->string, points_s);
}
```
In this function I prepare the new string of my text, and I use the function modify_string for change the string in the scene.
```c
void display_fps(scene *d)
{
    char *points = my_int_to_str(d->hub->fps);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "FPS: ");
    my_strcat(points_s, points);
    sfVector2f pos = {0, d->hub->mode.height - 110};
    text *t =
        create_text("./assets/josefin_sans/josefin_sans_light.ttf", points_s,
            sfWhite, pos);
    t->animate = animate_fps;
    sfText_setCharacterSize(t->text, 108);
    put_in_list(&d->texts, t);
}
```
In this function I create text with property fps of the screen structure.
