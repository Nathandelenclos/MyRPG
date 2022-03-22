# Texture
***
## [Structure](../include/struct.h)
```c
typedef struct texture_s {
    sfTexture *texture;
    sfIntRect rect;
    char *filename;
    void (*animate)(game_obj *);
    char *name;
} texture;
```
***
## Property
### Texture
sfTexture of CSFML.
```c
sfTexture *texture;
```
***
### Rect
Rect of texture (width, height).
```c
sfIntRect rect;
```
***
### Filename
Link of filename of texture.
```c
char *filename;
```
***
### Name
Name of this texture for identify for use in [object](./game_obj.md)
```c
char *name;
```
***
## Method
### Screen
Call in [time_manager](../manager/time_manager.c) for animate the [game_object](./game_obj.md) with this texture.
```c
void (*animate)(game_obj *);
```
***
## Functions
```c
void create_textures(scene *d);
```
load texture. [here](../manager/texture_manager.c)
***
```c
texture *create_texture(char *filename, char *name, sfIntRect rect);
```
Create texture. [here](../manager/texture_manager.c)
***
# Example
For this example I use the [dwarf.c](./dwarf.c) for create an example texture.
```c
void create_dwarf_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/dwarf_sheet.png";
    t->name = "dwarf";
    t->rect = create_rect(512, 32, 0, 32);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
```
In this function I create texture with default specific value. (You can use 'create_rect' function for create fast rect).