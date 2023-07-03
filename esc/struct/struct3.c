#include <stdio.h>
#include <stdlib.h>

typedef struct intventory
{
    char partName[30];
    int partNumber;
    float price;
    int stock;
    int reorder;
} Inventory;
union
{
    char c;
    short s;
    long b;
    float f;
    double b;
};

typedef struct address
{
    char streetAddress[25];
    char city[10];
    char state[3];
    int zipcode[6];
} Address;

typedef struct student
{
    char firstName[20];
    char lastName[20];
    int age;
    Address homeAddress;
} Student;

typedef struct test
{
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int c : 1;
    unsigned int d : 1;
    unsigned int e : 1;
    unsigned int f : 1;
    unsigned int g : 1;
    unsigned int h : 1;
    unsigned int i : 1;
    unsigned int j : 1;
    unsigned int k : 1;
    unsigned int l : 1;
    unsigned int m : 1;
    unsigned int n : 1;
    unsigned int o : 1;
    unsigned int p : 1;

} Testadicazzo;

struct customer
{
    char lastName[15];
    char firstName[15];
    unsigned int customerNumber;
    struct
    {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord, *customerPtr;
customerPtr = &customerRecord;
int main()
{
}