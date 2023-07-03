#include <stdio.h>
#include <string.h>

struct el
{
    char nome[20];
    char cognome[20];
    struct el *next;
};
typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;
//char ord_n(ListaDiElementi s, char nome[20], char cognome[20]);
char ord_c(ListaDiElementi s, char name[], char lastname[]);
void print(ListaDiElementi s);
int main()
{
    int choice;
    char name[20], lastname[20];
    ListaDiElementi s = malloc(sizeof(ElementoDiLista));
    strcpy(s->cognome, "Ferazzani");
    strcpy(s->nome, "Orlando");
    s = s->next;
    printf("Inserisci nome e cognome: ");
    *name = scanf("%s", s->nome);
    *lastname = scanf("%s", s->cognome);
    ord_c(s, name, lastname);
    /* printf("Vuoi ordinare per nome (1) o per cognome (2): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Inserisci un cognome: ");
        lastname = scanf("%s", s->cognome);
        printf("Inserisci un nome: ");
        name = scanf("%s", s->nome);
        ord_n(s, name, lastname);
    }
    else
    {
        printf("Inserisci un cognome: ");
        lastname = scanf("%s", s->cognome);
        printf("Inserisci un nome: ");
        name = scanf("%s", s->nome);
        ord_c(s, name, lastname);
    }*/
    print(s);
}

char ord_c(ListaDiElementi s, char name[], char lastname[])
{
    ListaDiElementi temp;
    if (s != NULL)
    {
        temp = s;
        if (lastname[0] < (s->next)->cognome[0])
        {
        }
        else if (lastname[0] > s->cognome[0])
        {
        }
        else if (lastname[0] == s->cognome[0])
        {
        }
    }
}