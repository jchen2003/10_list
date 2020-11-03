#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "construction.h"
#include <time.h>

int main(){
    srand(time(NULL));

    struct Pokemon *mew = new_pokemon(rand()%100+1,"Mew");
    struct Pokemon *mewtwo = new_pokemon(rand()%100+1,"Mewtwo");
    struct Pokemon *articuno = new_pokemon(rand()%100+1,"Articuno");
    struct Pokemon *zapdos = new_pokemon(rand()%100+1,"Zapdos");
    struct Pokemon *moltres = new_pokemon(rand()%100+1,"Moltres");

    mew->next = mewtwo;
    mewtwo->next = articuno;
    articuno->next = zapdos;
    zapdos->next = moltres;

    

    printf("Initial list:\n");
    print_list(mew);
    printf("\n");
    printf("Remove Mew:\n");
    mew = remove_node(mew,"Mew");
    print_list(mew);printf("\n");
    struct Pokemon *arceus = insert_front (mew,rand()%100+1,"Arceus");
    printf("Added Arceus to the front:\n");
    print_list(arceus);printf("\n");

    printf("Freeing list and adding Snorlax in front:\n");
    struct Pokemon *emp = free_list(arceus);

    struct Pokemon *snorlax = insert_front (emp,rand()%100+1,"Snorlax");
    print_list(snorlax);


}