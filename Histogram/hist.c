#include <stdio.h>
#define SIZE 5

int main (void)
{
    int n[SIZE] = {7, 5, 4, 3, 6};
    printf ("%s%13s%17s\n", "Element", "Value", "Histogram");

    for (size_t i = 0; i < SIZE; i++)
    {
        printf ("%7u%13d        ", i, n[i]);
        for (size_t j = 0; j < n[i]; j++)
        {
            printf ("%c", '*');
        }
        puts (" "); //end a histogram with a newline
    }
}