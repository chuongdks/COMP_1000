#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 20

int main (void){
    int input[SIZE] = {0};
    int searchKey = 0;
    
    //User enter number to be found
    printf ("Please enter a number to be searched in the random array of number: ");
    scanf ("%d", &searchKey);
    printf ("The search key is %d\n", searchKey);

    //Assign random number to array
    srand (time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        
        input[i] = rand() % 30;
        //printf ("Random number %d: %d\n", i, input[i]);
    }
    
    //Sort the random number in the array from smallest to largest
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (input[j] > input[j+1])
            {
                int temp = input[j+1];
                input[j+1] = input[j];
                input[j] = temp;
            }
        }
    }
    
    //Display sorted array
    for (int i = 0; i < SIZE; i++)
    {        
        printf ("Sorted Random number %d: %d\n", i, input[i]);
    } 

    //Find the user number using Binary Search
    int low = 0, high = SIZE - 1;
    int mid = (low + high) / 2;
    //|| (mid != 1)
    while ((searchKey != input[mid]) && (mid != 1))
    {        
        if (searchKey == input[mid])
        {
            printf ("The number has been found in array number %d", mid);
            break;
        }
        else if (searchKey < input[mid])
        {
            high = mid;
            mid = (low + high) / 2;
            printf ("High pos: %d\n", high);
            printf ("Mid pos: %d\n", mid);
            printf ("Low pos: %d\n", low);
        }
        else if (searchKey > input[mid])
        {
            low = mid;
            mid = (low + high) / 2;
            printf ("High pos: %d\n", high);
            printf ("Mid pos: %d\n", mid);
            printf ("Low pos: %d\n", low);         
        }
    }        
    printf ("The number has been found in array number %d", mid);
    return 0;
}
