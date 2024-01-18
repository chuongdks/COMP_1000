#include <stdio.h>

int main (void){

    int num, reverseNumber = 0, lastDigit = 0;

    printf("Enter the number to reverse: ");
    scanf("%d", &num);    

    while (num != 0){
        lastDigit = num % 10;
        reverseNumber = reverseNumber * 10 + lastDigit;
        num /= 10;
    }    
    printf("The reversed number is: %d", reverseNumber);
}

