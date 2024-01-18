#include <stdio.h>

int main (void){
    int remain = 0, num1 = 0, num2 = 0;
    printf ("Please enter number 1: \n");
    scanf ("%d", &num1);
    printf ("Please enter number 2: \n");
    scanf ("%d", &num2);
    remain = num1 % num2;
    printf ("Reminder of %d divide by %d is %d", num1, num2, remain);
}

