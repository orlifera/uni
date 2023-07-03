//derek dice liste sequenziali non liste collegate
#include <stdio.h>
#include <stdlib.h>

//struttura autoreferenziale
typedef struct pila
{
    unsigned int size;     //numero di elementi presenti nella pila
    unsigned int capacity; //capacità di memoria disponibile per allocare elementi
    int *data;             //puntatore al valore
} Pila;

//prototipi

void print_pila(Pila);
void init(Pila *);           //Inizializza pila con capacity 1 e senza nessun elemento,ovvero c'è spazio
void push(Pila *, int elem); //inserisce elemento elem sulla pila
int pop(Pila *);             //elimina elemento

int main()
{
    Pila p; //variabile p di tipo struct pila
    init(&p);

    print_pila(p);

    push(&p, 1);
    //print_pila(p);

    push(&p, 2);
    //print_pila(p);

    push(&p, 0);
    //print_pila(p);

    push(&p, 3);
    //print_pila(p);

    //pop(&p);
    print_pila(p);

    //int val = pop(&p);
    pop(&p);
    print_pila(p);
    pop(&p);
    print_pila(p);
    pop(&p);
    print_pila(p);
    pop(&p);
    print_pila(p);

    //printf("%d", val);
    printf("\n");
}

void print_pila(Pila p)
{ //stampa la pila
    for (int i = 0; i < p.size; i++)
    {                             //per ogni i minore di p.size(numero totale di elementi)
        printf("%d ", p.data[i]); //stampa data (valore) degli elementi della pila p
    }
    printf("\n");
}

void init(Pila *p)
{ //inizializza la pila con capacità 1 e size 0 (pila vuota)
    p->capacity = 1;
    p->size = 0;
    p->data = malloc(sizeof(int)); //alloca uno spazio di memoria nel membro data. ora c'è spazio per inserire un elemento
}

void push(Pila *p, int elem)
{ //inserisce elemento
    if (p->capacity == p->size)
    {                                                              //se la capacità è uguale alla dimensione (ovvero non c'è spazio per allocare un altro elemento)
        p->data = realloc(p->data, sizeof(int) * 2 * p->capacity); //nel puntatore a membro data viene modificata la dimensione della capacità
                                                                   //per poter avere spazio per inserire un nuovo elemento
        p->capacity *= 2;
    }
    p->data[p->size] = elem; //viene inserito un nuovo elemento elem alla fine della pila
    p->size++;               //viene aumentata la dimensione della pila altrimenti il nuovo elemento inserito sovrascrive l'ultimo elemento di prima
}

int pop(Pila *p)
{ //elimina elementi
    if (p->size > 0)
    {              //se ci sono elementi nella pila p
        p->size--; //viene decrementata la lista, ovvero vengono eliminati gli elementi dalla coda
    }
    return p->data[p->size]; //ritorna il valore di data nella posizione p->size
}
