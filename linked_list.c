#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "memory.h"

list* new_list() {
    return (list*)alocar(sizeof(list));
}

void clear(list* l) {
    node_s* atual;

    while (l->start != NULL) {
        atual = l->start;
        l->start = l->start->next_index;
        desalocar(atual);
    }

    desalocar(l);
}

void insert(list* l, int v) {
    node_s* novo = (node_s*)alocar(sizeof(node_s));
    novo->dado = v;
    novo->next_index = NULL;

    if (l->start == NULL) {
        novo->last_index = NULL;
        l->start = novo;
    } else {
        node_s* temp = l->start;

        while (temp->next_index != NULL) {
            temp = temp->next_index;
        }

        temp->next_index = novo;
        novo->last_index = temp;
    }
}

void show(list* l) {
    node_s* atual = l->start;

    while (atual != NULL) {
        printf(" %d%s", atual->dado, (atual->next_index ? " >" : ""));
        atual = atual->next_index;
    }
    printf("\n");
}

node_s* remove_element(list* l, int v) {
    node_s* target = find(l, v);

    if (target == NULL) {
        printf("Valor %d não encontrado\n", v);
        return NULL;
    }

    if (target->last_index != NULL) {
        target->last_index->next_index = target->next_index;
    } else {
        l->start = target->next_index;
    }

    if (target->next_index != NULL) {
        target->next_index->last_index = target->last_index;
    }

    return target;
}

void clear_value(list* l, int v) {
    node_s* del_element = remove_element(l, v);

    if (del_element != NULL) {
        desalocar(del_element);
    }
}

node_s* find(list* l, int v) {
    node_s* atual = l->start;
    while (atual != NULL && atual->dado != v) {
        atual = atual->next_index;
    }
    return atual;
}