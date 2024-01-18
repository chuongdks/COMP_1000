#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Insert(int a1[], int a2[], int a3[], int size);  // a1 is value, a2 is position, a3 is empty, size

int main(void){
    int n = 0;
    srand(time(NULL));

    printf ("Please enter a positive integer number (Zero to exit): ");
    scanf ("%d", &n);
    while (n < 0)
    {
        printf ("Your input is invalid.\n");
        printf ("Please enter a positive integer number (Zero to exit): ");
        scanf ("%d", &n);
    }

    int a1[n], a3[n];
    int a2[n];
    //int a2[6] = {0,0,1,0,2,4};

    //Initialize Array 1
    printf ("Array 1: ");
    for (int i = 0; i < n; i++)
    {
        a1[i] = i;
        printf ("%d ", a1[i]);
    }
    
    printf ("\n");

    //Initialize Array 2
    printf ("Array 2: ");
    for (int j = 0; j < n; j++)
    {
        a2[j] = (rand() % (j+1)); 
        printf ("%d ", a2[j]);
    }
    
    printf ("\n");

    //Initialize Array 3
    printf ("Array 3: ");
    Insert (a1, a2, a3, n);

    for (int j = 0; j < n; j++)
    {
        printf ("%d ", a3[j]);
    }

}

//a1[6] = {0,1,2,3,4,5}
//a2[6] = {0,0,1,0,2,4}

//a3[6] = {0}
//a3[6] = {1,0}
//a3[6] = {1,2,0}
//a3[6] = {3,1,2,0}
//a3[6] = {3,1,4,2,0}
//a3[6] = {3,1,4,2,5,0}

//a3[6] = {3,1,4,2,5,0}
//         0,1,2,3,4,5

int Insert(int a1[], int a2[], int a3[], int size)
{
    int first = 0;
    for (int i = 0; i < size; i++)
    {
        if (a2[i] < first)
        {
            for (int j = first; j > a2[i]; j--)
            {
                a3[j] = a3[j-1];
            }
        }
        a3[a2[i]] = a1[i];
        first++;
    }
}
