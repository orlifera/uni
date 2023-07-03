#include <stdio.h>

struct customer
{
    char lastname[25];
    char firstname[25];
    unsigned int customer;

    struct
    {
        char phonenumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipcode[6];
    } personal;
} customerRecord, *customerPtr;

int main()
{
    customerPtr = &customerRecord;
    printf("Enter customer's last name: ");
    scanf("%25s", customerRecord.lastname);
    printf("enter customer's first name: ");
    scanf("%s", customerRecord.firstname);
    printf("enter customer's number: ");
    scanf("%u", &customerRecord.customer);
    printf("Enter customer's phone number: ");
    scanf("%s", customerRecord.personal.phonenumber);
    printf("Enter customer's address: ");
    scanf("%s", customerRecord.personal.address);
    printf("Enter customer's city: ");
    scanf("%s", customerRecord.personal.city);
    printf("Enter customer's state: ");
    scanf("%s", customerRecord.personal.state);
    printf("Enter customer's zipcode: ");
    scanf("%s", customerRecord.personal.zipcode);
    printf("you entered the customer %s %s with customer number %u\n", customerPtr->lastname,
           customerPtr->firstname, customerPtr->customer);
    printf("Customer's phone number is: %s, ", customerPtr->personal.phonenumber);
    printf("Customer's address is %s, %s \n%s \n%s", customerPtr->personal.address, customerPtr->personal.city,
           customerPtr->personal.state, customerPtr->personal.zipcode);
}
