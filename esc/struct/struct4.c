#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum categoria
{
    motorino,
    moto,
    bicicletta,
    motocarro
} Categoria;
typedef struct Motoveicolo
{
    char plate[7];
    char make[25];
    char model[20];
    unsigned int engine;
    float power;
    Categoria cat;

} MV;

typedef struct proprietario
{
    char nome[30];
    char cognome[40];
    char CF[16];
} Proprietario;

typedef struct vocePra
{
    Proprietario owner;
    MV vehicle;
} VocePRA;