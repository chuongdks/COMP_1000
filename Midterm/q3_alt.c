#include <stdio.h>

int main (void){
    int num[12], lastDigit = 0;
    int test;
    long long isbn = 0;
    int counter = 0; //counter in the array
    int remainder = 0; //the remainder to check if the counter is Even or Odd
    int sum = 0, result = 0; //The sum and the result;

    //Enter the array of number
    printf ("Enter the first twelve digits of ISBN-13: ");
    scanf ("%l", &isbn);
    //Get the last digit of the isbn number
    while (isbn != 0)
    {
        lastDigit = isbn % 10;
        printf ("Last digit is: %d\n", lastDigit);
        isbn /= 10;
    }
    
    /*
    //The loop to check the position of the number and sum them
    for (counter = 0; counter < 12; counter++)
    {
        remainder = 0; //reset the remainder each loop, dont need to but in case
        remainder = counter % 2;
        //Since the counter in the array start with 0, we have to reverse the order which positon is multiply
        if (remainder == 0)
        {
            num[counter] *= 1; //If the counter (the position in the numer) is even, time it by 1
        }
        else
        {
            num[counter] *= 3; //If the counter (the position in the numer) is odd, time it by 3
        }
        sum += num[counter];
        //printf ("The %d loop is : %d\n", counter,num[counter]);
        //printf ("The sum is: %d\n", sum);
    }

    result = sum % 10;
    result = 10 - result;
    printf ("Check digit: %d\n", result);
    */
}

