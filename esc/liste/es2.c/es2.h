#ifndef STRUCT

typedef struct el
{
    int info;
    struct el *next;
} Elemento;
typedef Elemento *Lista;

#endif