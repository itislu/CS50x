#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");
    string phone = get_string("What's your phone number? ");

    printf("Name: %s\n", name);
    printf("Age: %i\n", age);
    printf("Phone number: %s\n", phone);
}