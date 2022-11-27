#include <stdio.h>
#include <ctype.h>

void spaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void hashes(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

int main(void)
{
    printf("give me dat size bruddah\n");
    int size;
    printf("size: ");
    scanf("%i", &size);

    printf("size is %i\n", size);

    if (size <= 0)
    {
        printf("Entered number too small, dawg!");
        return 0;
    }
    else if (isalpha(size))
    {
        printf("You must enter a number, silly fella!");
    }
    else
    {
        for (int i = 0; i < size + 1; i++)
        {
            spaces(size - i);
            hashes(i);
            printf(" ");
            hashes(i);
            spaces(size - i);

            printf("\n");
        }
    }
}