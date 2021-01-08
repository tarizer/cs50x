#include <stdio.h>
#include <cs50.h>

void print_n_char(char c, int n);

int main(void)
{
    int height;
    int line;

    height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    line = 0;
    while (line++ < height)
    {
        print_n_char(' ', height - line);
        print_n_char('#', line);
        printf("  ");
        print_n_char('#', line);
        printf("\n");
    }
}

// Print the given character n times
void print_n_char(char c, int n)
{
    while (n-- > 0)
    {
        printf("%c", c);
    }
}