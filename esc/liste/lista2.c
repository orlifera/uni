#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct gradenode
{
    char lastname[20];
    double grade;
    struct gradenode *nextPtr;
};
typedef struct gradenode GradeNode;
typedef GradeNode *GradeNodePtr;

int main()
{
    GradeNodePtr startPtr = NULL;
    GradeNodePtr currentPtr = NULL;
    GradeNodePtr previousPtr = NULL;

    GradeNodePtr newPtr = malloc(sizeof(GradeNode)); //ritorna puntatore a spazio di GradeNode
    strcpy(newPtr->lastname, "Adams");               //Jones dentro lastname
    newPtr->grade = 85.0;

    startPtr = newPtr;

    newPtr = malloc(sizeof(GradeNode));
    strcpy(newPtr->lastname, "Jones");
    newPtr->grade = 91.5;

    currentPtr = startPtr;        //passo adams dentro current
    currentPtr->nextPtr = newPtr; //assegno a nextPtr newPtr

    newPtr = malloc(sizeof(GradeNode));
    strcpy(newPtr->lastname, "Pritchard");
    newPtr->grade = 66.5;

    previousPtr = currentPtr;
    currentPtr = currentPtr->nextPtr; //currentPtr == jones
    currentPtr->nextPtr = newPtr;

    newPtr = malloc(sizeof(GradeNode));
    strcpy(newPtr->lastname, "Smith");
    newPtr->grade = 100.0;

    previousPtr = currentPtr;
    currentPtr = currentPtr->nextPtr;
    currentPtr->nextPtr = newPtr;

    newPtr = malloc(sizeof(GradeNode));
    strcpy(newPtr->lastname, "Thompson");
    newPtr->grade = 73.5;

    previousPtr = currentPtr;
    currentPtr = currentPtr->nextPtr;
    currentPtr->nextPtr = newPtr;

    currentPtr = startPtr;
    printf("Nome\tVoto\n");
    while (currentPtr != NULL)
    {

        printf("%s\t%f\n", currentPtr->lastname, currentPtr->grade);
        currentPtr = currentPtr->nextPtr;
    }
    currentPtr = startPtr;
    GradeNodePtr tempPtr;

    while (currentPtr != NULL)
    {
        tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
        free(tempPtr);
    }
    printf("tutti gli elementi eliminati\n");
}
