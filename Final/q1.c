#include <stdio.h>

int main (void){
    int input[10] = {0};
    int counter = 0, sum = 0;
    
    printf ("Please enter 10 number: ");
    for (int i = 0; i < 10; i++)
    {
        scanf ("%1d", &input[i]);
    }
    
    while (counter < 11)
    {
        if (counter % 2 == 0)
        {
            if (input[counter] % 2 != 0)
            {
                sum += input[counter]; 
            }
        }
        counter++;
    }
    
    printf ("The sum of odd numbers which are in the even index positions: %d", sum);
    return 0;
}
