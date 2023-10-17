#include <cs50.h>
#include <stdio.h>

long get_number(void);
int check_checksum(long number);
string check_type(long number);

int main(void)
{
    long number = get_number();

    int checksum = check_checksum(number);
    int type;
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
    // The modulo to get to each digit starting from the last
    long mod = 1;
    // The number of max digits that will be checked
    int digit = 16;
    int sum_last = 0, sum_sec_to_last = 0;
    while (digit > 0)
    {
        // Sum of every second digit, starting from last
        mod *= 10;
        sum_last += number % mod / (mod / 10);
        digit--;
        // Every other digit, starting from second to last, but each digit times 2 and then the sum of the digits of those products
        mod *= 10;
        int sec_to_last = number % mod / (mod / 10) * 2;
        if (sec_to_last > 9)
        {
            sec_to_last = sec_to_last / 10 + sec_to_last % 10;
        }
        sum_sec_to_last += sec_to_last;
        digit--;
    }
    return (sum_last + sum_sec_to_last) % 10;
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