/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** include struct
*/

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H

struct list_s {
    void *data;
    struct list_s *next;
};

typedef struct list_s node;

int put_in_list(node **list, void *data);
int free_list(node *head, void (*screen)(void *data));
void show_list(node *list);
void delete_in_list(node **list, void *data);
int len_list(node *list);
void insert_in_list(node *previous, void *data);
void delete_first(node **head);
void reverse_list(node **head_ref);
int put_in_end(node **list, void *data);

#endif