#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (void){
    int n = 0;
    printf ("Enter how many random number here: ");
    scanf ("%d", &n);

    int a[n];
    int temp = 0;
    int swap = -1;
    clock_t currentTime, endTime;

    printf("Before Bubble sorting:\n");
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
        printf ("%d. %d\n", i, a[i]);
    }

    currentTime = clock(); //Start the timer
    while (swap != 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            swap = 0;
            for (int j = 0; j < n - i - 1; j++) //Sort until the last array, when the first sort is done, leave the final index alone
            {
                if (a[j] > a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    swap ++;
                }
            }
            if (swap == 0) break;
        }
    }
    currentTime = clock() -  currentTime; //Stop the timer by using current time minus

    printf("After Bubble sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf ("%d. %d\n", i, a[i]);
    }
    
    float timer = (float)currentTime / CLOCKS_PER_SEC;
    printf ("Time taken for Bubble Sort: %f\n", timer);
}

