struct Pokemon{
    char name[256];
    int level;

    struct Pokemon *next;
};

struct Pokemon * new_pokemon(int l, char * n);

void poke_print(struct Pokemon *x);

void poke_modify(struct Pokemon *x, int l, char * n);

void print_list(struct Pokemon *x);

struct Pokemon *insert_front(struct Pokemon *x, int l, char *n);

struct Pokemon * free_list(struct Pokemon *x);

struct Pokemon * remove_node(struct Pokemon *front, char *data);