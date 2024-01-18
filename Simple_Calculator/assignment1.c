#include <stdio.h>

int main() {
    int a, b, result = 0;
    char op;
    char input = ' ';

    //Print the Welcome Message
    printf ("\nWelcome to my Command-Line\n");
    printf ("Calculator (CLC)\n");
    printf ("Developer: Pham Hoang Chuong  Version: 1\n");
    printf ("Date: September 25th 2023\n");
    printf ("Select one of the following items:\n");
    printf ("-------------------------------------------------------------------------\n");
    printf ("\nB) - Binary Mathematical Operations, such as addition and subtraction.\n");
    printf ("U) - Unary Mathematical Operations, such as square root, and log.\n");
    printf ("A) - Advances Mathematical Operations, using variables, arrays.\n");
    printf ("V) - Define variables and assign them values.\n");
    printf ("E) - Exit\n");
    
    //If the input is 'E', end the loop and end the program
    while (input != 'E') {
        printf("Select one of the following items: ");
        input = getchar();
        
        switch (input) {
            //Input 'B' do the math
            case 'b':
            case 'B':
                printf("Please enter the first number: ");
                scanf("%d", &a);

                printf("Please enter the operation (+, -, *, /): ");
                scanf(" %c", &op); //Must have a space for %c or else it wont work, google it but still dont know why

                printf("Please enter the second number: ");
                scanf("%d", &b);

                //Binary Math switch case to do the actual math
                switch (op) 
                {
                    case '+':
                        result = a + b;
                        break;
                    case '-':
                        result = a - b;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        if (b != 0) {
                            result = a / b;
                        } else {
                            printf("Division by zero is not allowed.\n");
                            result = 0; 
                        }
                        break;
                    default:
                        printf("Please select the right operation (+, -, *, /)\n");
                        result = 0; 
                }
                printf("The result is: %d\n", result);
                break;

            //Input U, A, V fall in the same case
            case 'u':   case 'U':
            case 'a':   case 'A':
            case 'v':   case 'V':
                puts ("Sorry, at this time I don't have enough knowledge to serve you in this category.");
                break;

            //Input E will exit the program
            case 'e':
            case 'E':
                puts ("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");
                break;

            //The default case if the user input wrong
            default:
                puts("Please select your option (B, U, A, V, E)");
                //printf ("Your previous choice is %c which is invalid\n", input); //The default case always appear after enter a case
                break;
        }
    }
}
