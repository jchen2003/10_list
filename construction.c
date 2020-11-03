#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "construction.h"

struct Pokemon * new_pokemon(int l, char * n){
    struct Pokemon *np;
    np = malloc(sizeof(struct Pokemon));

    strncpy(np->name, n, sizeof(np->name)-1);
    np->level = l;

    np->next = NULL;
    return np;
}

void poke_print(struct Pokemon *x){
    printf("Pokemon:%s Level:%d\n",x->name,x->level);
}

void poke_modify(struct Pokemon *x, int l, char * n){
    strncpy(x->name, n, sizeof(x->name)-1);
    x->level = l;
}

void print_list(struct Pokemon *x){
    printf("[ ");
    struct Pokemon *np = x;
    while(np != NULL){
        printf("%s ", np->name);
        np = np->next;
    }
    printf("]\n");
}

struct Pokemon *insert_front(struct Pokemon *x, int l, char *n){
    struct Pokemon *np = new_pokemon(l,n);
    np->next = x;
    return np;
}

struct Pokemon * free_list(struct Pokemon *x){
    while(x){
        free(x);
        x = x->next;
    }
    return x;
}

struct Pokemon * remove_node(struct Pokemon *front, char *data){
    struct Pokemon *np = front;
    if (strcmp (np->name, data) == 0){
        np = np->next;
        free(front);
        return np;
    }

    while(np){
        struct Pokemon *np_n = np->next;
        if (strcmp(np_n->name,data) == 0){
            np->next = np_n->next;
            free(np_n);
            return front;
        }
        np = np->next;
    }

    return front;
}