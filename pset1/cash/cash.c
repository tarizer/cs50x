#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
  int coins;
  int cents;
  float dollars;

  while ((dollars = get_float("Change owed: ")) < 0)
    ;
  cents = round(dollars * 100);
  // Get number of coins for the given change -> 4 types of coins: 25, 10, 5, 1
  coins = cents / 25;
  cents %= 25;
  coins += cents / 10;
  cents %= 10;
  coins += cents / 5;
  cents %= 5;
  coins += cents;
  // printf("Cents remaining: %i\n", cents);
  printf("%i\n", coins);
}