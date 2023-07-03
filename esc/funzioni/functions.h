#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *create_node(int value, Node *next);

void print_list(Node *list);

void print_inverted_list(Node *list);

int list_size(Node *list);

void push(Node **list, int value);

void insert_at(Node **list, int value, int pos);

void delete_at(Node **list, int pos);

// Recoursive

int read(Node *list, int pos);

void insert_at_rec(Node **list, int value, int pos);

void delete_at_rec(Node **list, int pos);

void ordinsert_rec(Node **list, int value);

void pre_insert(Node **list, int value);

void suf_insert(Node **list, int value);

void suf_insert_rec(Node **list, int value);

void remove_elements(Node **list, int nuber);

void reverse(Node **list);

void reverse_recursive(Node **list);

void sort_list(Node **list);

void append_list(Node **list_a, Node **list_b);