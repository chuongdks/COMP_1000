#include <stdio.h>

int main (void){
    int remain = 0, num;
    printf ("Please enter the number to check Even or Odd: \n");
    scanf ("%d", &num);
    remain = num % 2;
    if (remain == 0)
    {
        printf ("The number %d is an even number\n", num);
    }
    else
    {
        printf ("The number %d is an odd number\n", num);
    }
}

