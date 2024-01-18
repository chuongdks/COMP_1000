#include <stdio.h>
#include <math.h>

/*This Program is for a Simple Calculator, full instruction is in Assignment PDF (D:\uWindsor\SEMESTER_1\COMP-1400\Assignment) 
Problem:
+ Enter the wrong input to ask the user to enter again sometime cause the 'input variable to repeat itself or cause runtime error
    + Google it, mostly cause by getchar() creating a newline '\n' after
    + If use scanf for char, remember to leave a space, StackOverflow said so
+ (input != 'E') || (input != 'e') but Enter 'e' or 'E' will not terminate the program
+ For the 'A' case, press 'E' will exit to MAIN menu but so will other function
*/

int main() {
    int flag = 0; //the flag to check
    float num1 = 0, num2 = 0, numf = 0, result = 0;  //num variable for user input and the result
    //float a = 1.2, b = 9.6, c = 6.9, d = 11.4, e = 69.1; //variable that the user can change, testing only if too lazy to input
    float a = 0, b = 0, c = 0, d = 0, e = 0; //variable that the user can change
    char op, varName; //operator for the math function, variable name to choose variable and mode select for the case 'A'
    char op2, var1, var2; //User enter variable name from A to E
    char input = ' '; //User input mode at the start of the program
    char selectOperation = ' '; //char to select operation in this case only

    //Print the Welcome Message
    printf ("\nWelcome to my Command-Line\n");
    printf ("Calculator (CLC)\n");
    printf ("Developer: Pham Hoang Chuong  Version: 2\n");
    printf ("Date: October 2nd 2023\n");
    //Print what the user can do
    printf ("Select one of the following items:\n");
    printf ("-------------------------------------------------------------------------\n");
    printf ("\nB) - Binary Mathematical Operations, such as addition and subtraction.\n");
    printf ("U) - Unary Mathematical Operations, such as square root, and log.\n");
    printf ("A) - Advances Mathematical Operations, using variables, arrays.\n");
    printf ("V) - Define variables and assign them values.\n");
    printf ("E) - Exit\n");
    
    //If the input is 'E', end the loop and end the program
    while (input != 'E') 
    {
        printf("Select one of the following items (B, U, A, V, E): ");
        scanf (" %1c", &input);
        
        //Switch Input for each case B, U, A, V, E
        switch (input) 
        {
            //Input 'B' do the binary math
            case 'b':
            case 'B':
            {
                flag = 0; //reset the flag here, could have use "continue;" at the default case and put while (1) but only learnt that today  
                //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
                while (flag != 1)
                {
                    printf("Please enter the first number: ");
                    scanf("%f", &num1);

                    printf("Please enter the operation (+, -, *, /, %%, P, X, I): "); //Double %% to print out the character
                    scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why

                    printf("Please enter the second number: ");
                    scanf("%f", &num2);

                    //Binary Math switch case to do the actual math
                    switch (op) 
                    {
                        case '+':
                            result = num1 + num2;
                            flag = 1;
                            break;
                        case '-':
                            result = num1 - num2;
                            flag = 1;
                            break;
                        case '*':
                            result = num1 * num2;
                            flag = 1;
                            break;
                        case '/':
                            if (num2 != 0) 
                            {
                                result = num1 / num2;
                                flag = 1;
                            } 
                            else 
                            {
                                printf("Division by zero is not allowed.\n");
                                result = 0; 
                            }
                            break;
                        case '%':
                            if (num2 != 0) 
                            {
                                result = fmod (num1, num2);
                                flag = 1;
                            } 
                            else 
                            {
                                printf("Division by zero is not allowed.\n");
                                result = 0; 
                            }
                            break;                            
                        case 'P':
                            result = pow (num1, num2);
                            flag = 1;
                            break;            
                        case 'X':
                            if (num1 >= num2)
                            {
                                result = num1;
                                flag = 1;
                            }
                            else
                            {
                                result = num2;
                                flag = 1;
                            }
                            break;
                        case 'I':
                            if (num1 <= num2)
                            {
                                result = num1;
                                flag = 1;
                            }
                            else
                            {
                                result = num2;
                                flag = 1;
                            }
                            break;          
                        default:
                            printf("Please select the right operation (+, -, *, /, %, P, X, I)\n");
                            result = 0.0;
                    }
                }
                //If the code reach this point, the input is valid and the flag = 1
                printf("The result is: %.2f\n", result);
                break;
            }

            //Input U to do Unary Operation
            case 'u':   case 'U':
            {
                flag = 0; //reset the flag here, could have use "continue;" at the default case and put while (1) but only learnt today lol
                //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
                while (flag != 1)
                {
                    printf("Please enter the decimal number: ");
                    scanf("%f", &numf);

                    printf("Please enter the Unary operation (S, L, E, C, F): ");
                    scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why

                    //Unary Math switch case to do the actual math
                    switch (op)
                    {
                        case 'S':   case 's':
                            if (numf > 0)
                            {
                                result = sqrt (numf);
                                flag = 1;
                            }
                            else 
                            {
                                printf("Square root is not allowed for negative number\n");
                                result = 0;                                 
                            }
                            break;
                        case 'L':   case 'l':
                            if (numf > 0)
                            {
                                result = log (numf);
                                flag = 1;
                            }
                            else
                            {
                                printf("Logarithm is not allowed for negative number\n");
                                result = 0;                                   
                            }
                            break;
                        case 'E':   case 'e':
                            result = exp (numf);
                            flag = 1;
                            break;
                        case 'C':   case 'c':
                            result = ceil (numf);
                            flag = 1;
                            break;
                        case 'F':   case 'f':
                            result = floor (numf);
                            flag = 1;
                            break;
                        default:
                            printf("Please select the right operation (S, L, E, C, F)\n");
                            result = 0; 
                    }
                }
                //If the code reach this point, the input is valid and the flag = 1
                printf("The result is: %.2f\n", result);
                break; 
            }

            //Input A to do Math with variable Enter from 'A' Operation
            case 'a':
            case 'A':
            {
                printf("Select one of the following items to do calculation with variables:\n");
                printf("B) Binary Mathematical Operation\n");
                printf("U) Unary Mathematical Operation\n");
                printf("E) Exit\n");

                printf("Select one of the following items: ");
                scanf (" %1c", &selectOperation);

                //Switch case for B, U, E
                switch (selectOperation) 
                {
                    // Binary operation within A operation to put variable in it
                    case 'b':
                    case 'B':
                    {
                        flag = 0;
                        //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
                        while (flag != 1)
                        {
                            //Invalid input check for num1 using while loop with flag
                            flag = 0;                        
                            while (flag != 1)
                            {
                                printf("Please enter the first variable name or press other key except from A to E to enter a number: ");
                                scanf(" %1c", &var1);
                                if ((var1 >= 'A' && var1 <= 'E') || (var1 >= 'a' && var1 <= 'e')) 
                                {   
                                    switch (var1) 
                                    {
                                        case 'A':   case 'a':
                                            num1 = a;
                                            flag = 1;
                                            break;
                                        case 'B':   case 'b':
                                            num1 = b;
                                            flag = 1;
                                            break;
                                        case 'C':   case 'c':
                                            num1 = c;
                                            flag = 1;
                                            break;
                                        case 'D':   case 'd':
                                            num1 = d;
                                            flag = 1;
                                            break;
                                        case 'E':   case 'e':
                                            num1 = e;
                                            flag = 1;
                                            break;
                                        //No default case cuz if the user enter anything other than A, B, C, D, E, then num1 will be a number
                                    }
                                }
                                else
                                {
                                    printf("Please enter the first number: ");
                                    scanf("%f", &num1);
                                    flag = 1;
                                }
                            }

                            printf("Please enter the operation (+, -, *, /, %%, P, X, I): "); //Double %% to print out the character
                            scanf(" %1c", &op2);

                            //Invalid input check for num2 using while loop with flag
                            flag = 0;
                            while (flag != 1)
                            {
                                printf("Please enter the second variable name or press other key except from A to E to enter a number: ");
                                scanf(" %1c", &var2);

                                if ((var2 >= 'A' && var2 <= 'E') || (var2 >= 'a' && var2 <= 'e')) 
                                {   
                                    switch (var2) 
                                    {
                                        case 'A':   case 'a':
                                            num2 = a;
                                            flag = 1;
                                            break;
                                        case 'B':   case 'b':
                                            num2 = b;
                                            flag = 1;
                                            break;
                                        case 'C':   case 'c':
                                            num2 = c;
                                            flag = 1;
                                            break;
                                        case 'D':   case 'd':
                                            num2 = d;
                                            flag = 1;
                                            break;
                                        case 'E':   case 'e':
                                            num2 = e;
                                            flag = 1;
                                            break;
                                        //No default case cuz if the user enter anything other than A, B, C, D, E, then num1 will be a number
                                        default:
                                            break;
                                    }
                                }
                                else
                                {
                                    printf("Please enter the second number: ");
                                    scanf("%f", &num2);
                                    flag = 1;
                                }
                            }

                            //Invalid input check for operator using while loop with flag
                            switch (op2) 
                            {
                                case '+':
                                    result = num1 + num2;
                                    flag = 1;
                                    break;
                                case '-':
                                    result = num1 - num2;
                                    flag = 1;
                                    break;
                                case '*':
                                    result = num1 * num2;
                                    flag = 1;
                                    break;
                                case '/':
                                    if (num2 != 0) 
                                    {
                                        result = num1 / num2;
                                        flag = 1;
                                    } 
                                    else 
                                    {
                                        printf("Division by zero is not allowed.\n");
                                        result = 0;
                                        flag = 0;
                                    }
                                    break;
                                case '%':
                                    if (num2 != 0) 
                                    {
                                        result = fmod (num1, num2);
                                        flag = 1;
                                    } 
                                    else 
                                    {
                                        printf("Division by zero is not allowed.\n");
                                        result = 0; 
                                        flag = 0;
                                    }
                                    break;                            
                                case 'P':
                                    result = pow (num1, num2);
                                    flag = 1;
                                    break;            
                                case 'X':
                                    if (num1 >= num2)
                                    {
                                        result = num1;
                                        flag = 1;
                                    }
                                    else
                                    {
                                        result = num2;
                                        flag = 1;
                                    }
                                    break;
                                case 'I':
                                    if (num1 <= num2)
                                    {
                                        result = num1;
                                        flag = 1;
                                    }
                                    else
                                    {
                                        result = num2;
                                        flag = 1;
                                    }              
                                    break;                    
                                default:
                                    printf("Please select the right operation (+, -, *, /, %, P, X, I)\n");
                                    result = 0;
                                    flag = 0;
                            }                            
                        }                    
                        //If the code reach this point, the input is valid and the flag = 1
                        printf("The result of the advanced binary operation is: %.2f\n", result);
                        break;
                    }

                    // Unary operation
                    case 'u':
                    case 'U':
                    {                        
                        flag = 0;
                        //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
                        while (flag != 1)
                        {
                            //Invalid input check for number using while loop with flag
                            flag = 0;
                            while (flag != 1)
                            {
                                printf("Please enter the first variable name or press other key except from A to E to enter a number: ");
                                scanf(" %1c", &var1);
                                if ((var1 >= 'A' && var1 <= 'E') || (var1 >= 'a' && var1 <= 'e')) 
                                {
                                    switch (var1) 
                                    {
                                        case 'A':   case 'a':
                                            numf = a;
                                            flag = 1;
                                            break;
                                        case 'B':   case 'b':
                                            numf = b;
                                            flag = 1;
                                            break;
                                        case 'C':   case 'c':
                                            numf = c;
                                            flag = 1;
                                            break;
                                        case 'D':   case 'd':
                                            numf = d;
                                            flag = 1;
                                            break;
                                        case 'E':   case 'e':
                                            numf = e;
                                            flag = 1;
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                else
                                {
                                    printf("Please enter the number: ");
                                    scanf("%f", &numf);
                                    flag = 1;
                                }
                            }

                            //Invalid input check for operator using while loop with flag
                            printf("Please enter the Unary operation (S, L, E, C, F): ");
                            scanf(" %1c", &op2); //Must have a space for %c or else it wont work, google it but still dont know why

                            //Unary Math switch case to do the actual math
                            switch (op2)
                            {
                                case 'S':   case 's':
                                    if (numf > 0)
                                    {
                                        result = sqrt (numf);
                                        flag = 1;
                                    }
                                    else
                                    {
                                        printf("Square root is not allowed for negative number\n");
                                        result = 0;     
                                        flag = 0;                                        
                                    }
                                    break;
                                case 'L':   case 'l':
                                    if (numf > 0)
                                    {
                                        result = log (numf);
                                        flag = 1;
                                    }
                                    else 
                                    {
                                        printf("Square root is not allowed for negative number\n");
                                        result = 0;     
                                        flag = 0;     
                                    }
                                    break;
                                case 'E':   case 'e':
                                    result = exp (numf);
                                    flag = 1;
                                    break;
                                case 'C':   case 'c':
                                    result = ceil (numf);
                                    flag = 1;
                                    break;
                                case 'F':   case 'f':
                                    result = floor (numf);
                                    flag = 1;
                                    break;
                                default:
                                    printf("Please select the right operation (S, L, E, C, F)\n");
                                    result = 0; 
                                    flag = 0;
                            }                            
                        }
                        //If the code reach this point, the input is valid and the flag = 1
                        printf("The result is: %.2f\n", result);
                        break;                        
                    }

                    // Exit
                    case 'e':
                    case 'E':
                        puts("Exiting advanced operations.");
                        printf ("Select one of the following items:\n");
                        printf ("-------------------------------------------------------------------------\n");
                        printf ("\nB) - Binary Mathematical Operations, such as addition and subtraction.\n");
                        printf ("U) - Unary Mathematical Operations, such as square root, and log.\n");
                        printf ("A) - Advances Mathematical Operations, using variables, arrays.\n");
                        printf ("V) - Define variables and assign them values.\n");
                        printf ("E) - Exit\n");
                        break;

                    default:
                        puts("Invalid operation type. Please select B, U, or E.");
                        break;
                }
                break;
            }

            //Input V to assign variable from A to E
            case 'v':   case 'V':
            {
                flag = 0; //reset the flag here, could have use "continue;" at the default case and put while (1) but only learnt today lol
                //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
                while (flag != 1)
                {
                    printf("Please enter the name of the variable: ");
                    scanf(" %1c", &varName);

                    printf("Please assign a number to the variable: ");
                    scanf(" %f", &numf); //Must have a space for %c or else it wont work, google it but still dont know why

                    //Assign Variable
                    switch (varName) 
                    {
                        case 'A':   case 'a':
                            a = numf;
                            flag = 1;
                            break;
                        case 'B':   case 'b':
                            b = numf;
                            flag = 1;
                            break;
                        case 'C':   case 'c':
                            c = numf;
                            flag = 1;
                            break;
                        case 'D':   case 'd':
                            d = numf;
                            flag = 1;
                            break;
                        case 'E':   case 'e':
                            e = numf;
                            flag = 1;
                            break;
                        default:
                            printf("Please enter the right name for the variable (A, B, C, D, E)\n");
                            result = 0; 
                    }
                }
                //If the code reach this point, the input is valid and the flag = 1
                printf ("The variable A is: %.2f\n", a);
                printf ("The variable B is: %.2f\n", b);
                printf ("The variable C is: %.2f\n", c);
                printf ("The variable D is: %.2f\n", d);
                printf ("The variable E is: %.2f\n", e);
                break;
            }

            //Input E will exit the program
            case 'E':
            {
                puts ("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");
                break;
            }

            //The default case if the user input wrong
            default:
            {
                puts("\nPlease select your option (B, U, A, V, E)");
                break;
            }
        }
    }
    return 0;
}
