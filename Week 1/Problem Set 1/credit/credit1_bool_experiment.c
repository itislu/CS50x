#include <cs50.h>
#include <stdbool.h> // Learned later one has to include include a header file for bools
#include <stdio.h>

long get_number(void);
string check_type(long number);
bool check_validity(long number);
void print(bool validity, string type);

int main(void)
{
    // Ask user for number
    long number = get_number();

    // Check if AmEx, Visa or Mastercard, or already invalid
    string type = check_type(number);

    // Check validity of number with Luhn's Algorithm, else invalid
    bool validity = check_validity(number);

    // Print type of credit card
    print(validity, type);
}

long get_number(void)
{
    long number = get_long("Number: ");
    return number;
}

string check_type(long number)
{
    string type;
    printf("%c\n", (char) number);
    if ((char) number == 3)
    {
        return type = "AMEX";
    }
    else if ((char) number == 4)
    {
        return type = "VISA";
    }
    else if ((char) number == 5)
    {
        return type = "MASTERCARD";
    }
    else
    {
        // Maybe change to INVALID if spoofed card numbers make it through
        return type = "UNKONWN";
    }
}

bool check_validity(long number)
{
    int i = 1;
    long mod = 1;
    // Not sure if of both are initialized to 0 with this here
    int sum_last, sum_s_to_last = 0;
    while (i <= 16)
    {
        mod = mod * 10;
        sum_last = sum_last + number % mod / (mod / 10);
        i++;
        mod = mod * 10;
        int s_to_last = number % mod / (mod / 10) * 2;
        // Can an if conditional stay without an else and will just skip?
        if (s_to_last > 9)
        {
            s_to_last = s_to_last / 10 + s_to_last % 10;
        }
        sum_s_to_last = sum_s_to_last + s_to_last;
        i++;
    }
    bool validity;
    if ((sum_last + sum_s_to_last) % 10 == 0)
    {
        return validity = 1;
    }
    else
    {
        return validity = 0;
    }
}

void print(bool validity, string type)
{
    if (validity)
    {
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}