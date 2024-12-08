#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    struct node* last_index;
    int dado;
    struct node* next_index;
} node_s;

typedef struct list_data {
    node_s* start;
} list;

list* new_list();
void clear(list* l);

void insert(list* l, int v);
void show(list* l);

node_s* remove_element(list* l, int v);
void clear_value(list* l, int v);

node_s* find(list* l, int v);

#endif