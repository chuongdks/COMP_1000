#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (void){
    int num = 0, counter = 0;
    int a[30];
    while (1)
    {
        printf ("Please enter number from 0 to 20 to count that number: ");
        scanf ("%d", &num);
        if (num >= 0 && num <= 20)
        break;
    }

    printf("The List of number is:\n");
    for (int i = 0; i < 30; i++)
    {
        a[i] = (rand() % 21); //remainder of a random number is limited to the remainder only
        printf ("%d. %d\n", i, a[i]);
    }

    for (int i = 0; i < 30; i++)
    {
        if (a[i] == num)
        {
            counter++;
        }
    }

    printf ("The frequency of number %d is %d\n", num, counter);
}

