#include <stdio.h>
//#include <cs50.h>

int main(void)
{
    // Name should be less than 50 characters -> avoid using cs50.h
    char name[50];

    printf("Wie heisst du? ");
    scanf("%s", name);
    printf("hallo, %s\n", name);
}