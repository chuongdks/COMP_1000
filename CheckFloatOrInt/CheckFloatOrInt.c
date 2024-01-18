// Program to check if scanf from user is a float number
#include <stdio.h>

float CheckInt ()
{
    float x;
    while (scanf("%f", &x) != 1) //If user input a decimal then scanf will return 1, same thing for any format specifier
    {
        printf ("Please enter a decimal number, not a character: \n");
        scanf ("%f", &x);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return x;
}

int main() {
    float result = 0;
    printf ("Please enter a decimal number: \n");
    result = CheckInt ();
    printf ("You have enter a float number %.2f\n", result);
    return 0;
}