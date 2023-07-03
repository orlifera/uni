#include <stdio.h>
#include <stdlib.h>

int main()
{
    int accnumber;
    float currbal, dollam;
    char name[20];
    FILE *ofPtr, *tfPtr, *nfPtr;
    ofPtr = fopen("oldmast.dat", "r");
    tfPtr = fopen("trans.dat", "r");
    nfPtr = fopen("newmast.dat", "w");

    fscanf(ofPtr, "%d%-s%-f", &accnumber, name, &currbal);
    fscanf(tfPtr, "%d%-f", &accnumber, &dollam);
    fprintf(nfPtr, "%d%-s%-f", accnumber, name, currbal);
}