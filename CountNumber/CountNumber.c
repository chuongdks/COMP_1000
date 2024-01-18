#include <stdio.h>

int main (void){

    int num, countNumber, lastDigit = 0, counter = 0;

    printf("Enter the number to be count: ");
    scanf("%d", &num);    
    printf("Enter the number that you want to count: ");
    scanf("%d", &countNumber);    
    while (num != 0){
        lastDigit = num % 10;
        num /= 10;
        if (lastDigit == countNumber)
        {
            counter++;
        }
        printf ("The last digit is: %d\n", lastDigit);
    }    
    printf("The frequency of that number is: %d\n", counter);
}

