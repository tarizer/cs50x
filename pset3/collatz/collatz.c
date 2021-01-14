#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// Prototypes
int collatz(int n);

int steps;

int main(int argc, char *argv[])
{
  steps = 0;

  if (argc != 2)
  {
    printf("Usage: ./collatz (number)\n");
    return (1);
  }
  steps = collatz(atoi(argv[1]));
  printf("Steps: %i\n", steps);
}

int collatz(int n)
{
  if (n != 1)
  {
    printf("Step: %i - n: %i\n", steps++, n);
    // Even number
    if ((n % 2) == 0)
    {
      return collatz(n / 2);
    }
    // Odd numbers
    else
    {
      return collatz((3 * n + 1));
    }
  }
  // Base case
  return steps;
}