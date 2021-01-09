#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>

int check_card_checksum(long truncated_number);
void display_card_name(long card_number, int digits);

int main(void)
{
    long card_number;
    int digits;

    // Prompt user for input
    while ((card_number = get_long("Number: ")) < 0);
    // Check checksum validity
    if ((digits = check_card_checksum(card_number)) != 0) // Valid checksum
    {
        display_card_name(card_number, digits);
    }
    else
    {
        printf("INVALID\n");    // Invalid checksum or invalid number
    }
}

int check_card_checksum(long truncated_number)
{
    // if checksum is valid returns number of digits else returns 0
    int digits;
    int checksum;

    digits = 0;
    checksum = 0;
    // truncated_number = card_number;
    while (truncated_number > 0)
    {
        digits++;
        if (digits % 2 == 1) // odd
        {
            checksum += truncated_number % 10;
        }
        else // even
        {
            if ((truncated_number % 10) * 2 > 9) // Add products’ digits (i.e., not the products themselves) together
            {
                checksum += ((truncated_number % 10) * 2) / 10 + ((truncated_number % 10) * 2) % 10; // Can't be more than 2 digits (max 9 x 2 = 18)
            }
            else
            {
                checksum += (truncated_number % 10) * 2; // Add the single digit
            }
        }
        truncated_number /= 10;
    }
    if (checksum % 10 == 0) // Checksum validity -> last digit must be equal to 0
    {
        return (digits); // Checksum valid
    }
    else
    {
        return (0);
    }
}

void display_card_name(long card_number, int digits)
{
    int first_two_digits;

    first_two_digits = card_number / pow(10, digits - 2);
    // Check credit card length and starting digit
    if (digits == 15 && (first_two_digits == 34 || first_two_digits == 37)) // American Express
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && (first_two_digits >= 51 && first_two_digits <= 55))    // Master Card
    {
        printf("MASTERCARD\n");
    }
    else if ((digits == 13 || digits == 16) && first_two_digits / 10 == 4) // Visa
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");    // Invalid checksum or invalid number
    }
}