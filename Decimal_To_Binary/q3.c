#include <stdio.h>

void DecToBin (int num)
{
    int binaryNumber[100];
    int remainder = 0;
    int counter = 0;
    
    //Take the remainder of decimal number by 2 and store it in an array, that is the LSB of that binary number
    while (num > 0)
    {
        binaryNumber[counter] = num % 2;
        num /=  2; //Keep dividing by 2 until num = 0 (1/2 = 0) 
        counter++;
    }

    //Reverse the counter to "DISPLAY" binary number from integer
    for (int i = counter - 1; i >= 0; i--)
    {
        printf ("%d ", binaryNumber[i]);
    }
}

int main (void){
    int num = 0;

    printf ("Enter the decimal number to be convert to Binary: ");
    scanf ("%d", &num);

    DecToBin (num);
}

