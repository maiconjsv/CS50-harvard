#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{

    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row++)
    {
        print_row(height - row - 1, row + 1);
    }
}
void print_row(int spaces, int bricks)
{
    for (int s = 0; s < spaces; s++)
    {
        printf(" ");
    }

    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
