#include <cs50.h>
#include <stdio.h>

long get_number(void);
int check_checksum(long number);
string check_type(long number);

int main(void)
{
    long number = get_number();

    int checksum = check_checksum(number);
    string type;
    if (checksum == 0)
    {
        type = check_type(number);
    }
    else
    {
        type = "INVALID";
    }

    // Print type of credit card
    printf("%s\n", type);
}

// Asks user for number
long get_number(void)
{
    long number = get_long("Number: ");
    return number;
}

// Checksum of number with Luhn's Algorithm
int check_checksum(long number)
{
    // Number of max digits that will be checked
    int place = 16, sum = 0;

    // Calculates the sum of every second digit starting from last + every other digit, starting from second to last, but each digit times 2 and then the sum of the digits of those products
    while (place > 0)
    {
        int digit = number % 10;

        // This if statement is for every second digit starting from second to last
        if (place % 2 != 0)
        {
            digit *= 2;
            if (digit >= 10)
            {
                digit -= 9;     // The same as counting the digits together
            }
        }
        sum += digit;
        number /= 10;   // Goes to the next digit from the back
        place--;
    }
    return sum % 10;    // Total's last digit has to be 0 to be valid
}

// Checks with first digits and length if AmEx, Visa or Mastercard, else invalid
string check_type(long number)
{
    string type;
    // American Express has 15 digits and starts with 34 or 37
    if ((number >= 340000000000000 && number < 350000000000000) || (number >= 370000000000000 && number < 380000000000000))
    {
        return type = "AMEX";
    }
    // Visa has 13 or 16 digits and starts with 4
    else if ((number >= 4000000000000 && number < 5000000000000) || (number >= 4000000000000000 && number < 5000000000000000))
    {
        return type = "VISA";
    }
    // MasterCard has 16 digits and starts with 51, 52, 53, 54, or 55
    else if (number >= 5100000000000000 && number < 5600000000000000)
    {
        return type = "MASTERCARD";
    }
    else
    {
        return type = "INVALID";
    }
}