#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct incidente
{
    char targa[7];
    char data[5];
    char resp;
} Inc;
typedef Inc *inc;

typedef struct polizza
{
    char targa[7];
    char classe[2];
    char nome[20];
} Pol;
typedef Pol *pol;

int main()
{
}