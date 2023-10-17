// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol!\n");    // Added "!" myself
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lowercase = false, uppercase = false, number = false, symbol = false;
    int i = 0;
    while (password[i] != '\0')
    {
        if (lowercase == false && islower(password[i]))
        {
            lowercase = true;
        }
        else if (uppercase == false && isupper(password[i]))
        {
            uppercase = true;
        }
        else if (number == false && isdigit(password[i]))
        {
            number = true;
        }
        else if (symbol == false && !isalnum(password[i]))
        {
            symbol = true;
        }

        // Starts checking if all conditions are met once 4 characters have been checked (because 4 conditions all have to be true)
        if (i >= 3 && lowercase && uppercase && number && symbol)
        {
            return true;
        }
        i++;
    }
    return false;
}
