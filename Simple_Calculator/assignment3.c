#include <stdio.h>
#include <math.h>

/*
This Program is for a Simple Calculator, full instruction is in Assignment PDF (D:\uWindsor\SEMESTER_1\COMP-1400\Assignment) 

 **** Problem ****

_ Enter the wrong input to ask the user to enter again sometime cause the 'input variable to repeat itself or cause runtime error
    + Google it, mostly cause by getchar() or scanf() creating a newline '\n' after
    + If use scanf for char, remember to leave a space, StackOverflow said so

_ (input != 'E') || (input != 'e') but Enter 'e' or 'E' will not terminate the program

_ For the 'A' case, press 'E' will exit to MAIN menu but so will other function

_ For Assignment 3
    + Cannot figure out how to create, where to put a function that return the list of available option since the main code use 
'break' to break the switch case and bring back to the available option
    + Doesn't know what to put for function 'E' to exit the switch case
*/

void WelcomeMessages (void);

void UserInstruction (void);

void UserInstructionForAdvance (void);

float BinaryMath (float num1, float num2, char op, int check1, int check2);

float UnaryMath (float num1, char op, int check1);

float BinaryMathWithVariable (char var1, char var2, char op, float a, float b, float c, float d, float e);

float UnaryMathWithVariable (char var1, char op, float a, float b, float c, float d, float e);

void PrintVariable (float a,float b,float c,float d,float e);

int main() {
    int flag = 0; //the flag to check
    float num1 = 0, num2 = 0, result = 0;  //num variable for user input and the result
    //float a = 0, b = 9.6, c = 6.9, d = 11.4, e = -9.1; //variable that the user can change, testing only if too lazy to input
    float a = 0, b = 0, c = 0, d = 0, e = 0; //variable that the user can change
    char op; //operator for the math function, variable name to choose variable and mode select for the case 'A'
    char var1, var2; //User enter variable name from A to E
    char input = ' '; //User input mode at the start of the program
    char selectOperation = ' '; //char to select operation in this case only
    int check1 = 0, check2 = 0; //check if the input is a string or digit

    WelcomeMessages ();
    UserInstruction ();
    
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
                printf("Please enter the first number: ");
                check1 = scanf("%f", &num1); //Output of a scanf is 1 if user enter in a float type                
                int c; //Clear input buffer for num1, https://www.youtube.com/watch?v=N7-MueK2CX8&ab_channel=PortfolioCourses
                while ((c = getchar()) != '\n' && c != EOF) {}    

                printf("Please enter the operation (+, -, *, /, %%, P, X, I): "); //Double %% to print out the character
                scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why

                printf("Please enter the second number: ");        
                check2 = scanf("%f", &num2); //Output of a scanf is 1 if user enter in a float type

                result = BinaryMath (num1, num2, op, check1, check2);
                printf("The result is: %.2f\n", result);
                break;
            }

            //Input U to do Unary Operation
            case 'u':   case 'U':
            {
                printf("Please enter the first number: ");
                check1 = scanf("%f", &num1); //Output of a scanf is 1 if user enter in a float type                
                int c; //Clear input buffer for num1, https://www.youtube.com/watch?v=N7-MueK2CX8&ab_channel=PortfolioCourses
                while ((c = getchar()) != '\n' && c != EOF) {}    

                printf("Please enter the Unary operation (S, L, E, C, F): ");
                scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why    

                result = UnaryMath (num1, op, check1);                
                printf("The result is: %.2f\n", result);
                break; 
            }

            //Input A to do Math with variable Enter from 'A' Operation
            case 'a':
            case 'A':
            {
                UserInstructionForAdvance ();

                printf("Select one of the following items: ");
                scanf (" %1c", &selectOperation);

                //Switch case for B, U, E
                switch (selectOperation) 
                {
                    // Binary operation within A operation to put variable in it
                    case 'b':
                    case 'B':
                    {                        
                        printf("Please enter the first variable name or press other key except from A to E to enter a number: ");
                        scanf(" %1c", &var1);                    
                      
                        printf("Please enter the operation (+, -, *, /, %%, P, X, I): "); //Double %% to print out the character
                        scanf(" %1c", &op);

                        printf("Please enter the second variable name or press other key except from A to E to enter a number: ");
                        scanf(" %1c", &var2);

                        result = BinaryMathWithVariable (var1, var2, op, a, b, c, d, e);
                        printf("The result of the advanced Binary operation is: %.2f\n", result);
                        break;
                    }
                    // Unary operation
                    case 'u':
                    case 'U':
                    {                          
                        printf("Please enter the first variable name or press other key except from A to E to enter a number: ");
                        scanf(" %1c", &var1);

                        printf("Please enter the Unary operation (S, L, E, C, F): ");
                        scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why
                        int c; //Clear input buffer for num1, https://www.youtube.com/watch?v=N7-MueK2CX8&ab_channel=PortfolioCourses
                        while ((c = getchar()) != '\n' && c != EOF) {}    

                        result = UnaryMathWithVariable (var1, op, a, b, c, d, e);                                       
                        printf("The result of the advanced Unary operation is: %.2f\n", result);
                        break;                        
                    }

                    // Exit
                    case 'e':
                    case 'E':
                        puts("Exiting advanced operations.");
                        UserInstruction ();
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
                    scanf(" %1c", &op);

                    printf("Please assign a number to the variable: ");
                    scanf(" %f", &num1); //Must have a space for %c or else it wont work, google it but still dont know why

                    //Assign Variable
                    switch (op) 
                    {
                        case 'A':   case 'a':
                            a = num1;
                            flag = 1;
                            break;
                        case 'B':   case 'b':
                            b = num1;
                            flag = 1;
                            break;
                        case 'C':   case 'c':
                            c = num1;
                            flag = 1;
                            break;
                        case 'D':   case 'd':
                            d = num1;
                            flag = 1;
                            break;
                        case 'E':   case 'e':
                            e = num1;
                            flag = 1;
                            break;
                        default:
                            printf("Please enter the right name for the variable (A, B, C, D, E)\n");
                    }
                }
                //If the code reach this point, the input is valid and the flag = 1
                PrintVariable (a,b,c,d,e);
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

void WelcomeMessages (void)
{
    //Print the Welcome Message
    printf ("\nWelcome to my Command-Line\n");
    printf ("Calculator (CLC)\n");
    printf ("Developer: Pham Hoang Chuong  Version: 3\n");
    printf ("Date: October 19th 2023\n");
}

void UserInstruction (void)
{
    //Print what the user can do
    printf ("Select one of the following items:\n");
    printf ("-------------------------------------------------------------------------\n");
    printf ("\nB) - Binary Mathematical Operations, such as addition and subtraction.\n");
    printf ("U) - Unary Mathematical Operations, such as square root, and log.\n");
    printf ("A) - Advances Mathematical Operations, using variables, arrays.\n");
    printf ("V) - Define variables and assign them values.\n");
    printf ("E) - Exit\n");
}

void UserInstructionForAdvance (void)
{
    printf("Select one of the following items to do calculation with variables:\n");
    printf("B) Binary Mathematical Operation\n");
    printf("U) Unary Mathematical Operation\n");
    printf("E) Exit\n");
}

float BinaryMath (float num1, float num2, char op, int check1, int check2)
{
    int flag = 0; //reset the flag here, could have use "continue;" at the default case and put while (1) but only learnt that today  
    float result = 0;
    //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
    while (flag != 1)
    {        
        //Check if num1 is valid
        while (check1 != 1) //If the size of num1 is different to the size of float type, ask user to input again
        {
            printf ("Please enter a decimal number for your first number: \n");
            check1 = scanf ("%f", &num1);
            //The 2 line of code below check for input buffering, found it HERE: https://www.youtube.com/watch?v=N7-MueK2CX8&ab_channel=PortfolioCourses
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}       
        }

        //Enter the operator again if something is wrong
        while (1) //while true, check if user already input the right operator, if op is right ignore, else ask to input again
        {
            if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == 'P' || op == 'X' || op == 'I')
            { 
                break;
            } 
            else
            {
                printf("Please enter a valid operation (+, -, *, /, %%, P, X, I): "); //Double %% to print out the character
                scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {} 
            }
        }

        //Check if num2 is valid
        while (check2 != 1 || (op == '/' && num2 == 0) || (op == '%' && num2 == 0)) //If the size of num1 is different to the size of float type, ask user to input again
        {
            printf ("Please enter a decimal number for your second number: \n");
            check2 = scanf ("%f", &num2);        
            //The 2 line of code below check for input buffering, need to learn moar about this, found it on internet so that printf wont be infinite
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}           
        }

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
                    printf("Remainder by zero is not allowed.\n");
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
                printf("Please select the right operation (+, -, *, /, %%, P, X, I)\n");
                scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why
                result = 0.0;
                flag = 0;
        }            
        
    }
    //If the code reach this point, the input is valid so return the result and assign it to a variable
    return result;
}

float UnaryMath (float num1, char op, int check1)
{
    int  flag = 0; //reset the flag here, could have use "continue;" at the default case and put while (1) but only learnt today lol
    float result = 0;
    //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
    while (flag != 1)
    {
        //Check if num1 is valid
        while (check1 != 1 || flag == 2) //If the size of num1 is different to the size of float type, ask user to input again
        {
            printf ("Please enter a decimal number for your first number: \n"); 
            check1 = scanf ("%f", &num1);
            if (op == 'S' || op == 'L') //Doesnt cover for the case 'L' where input is equal to 0
            {
                if (num1 >= 0.0)
                {
                    flag = 0;
                }
                else
                {
                    flag = 2;
                } 
            }
            //The 2 line of code below check for input buffering, found it HERE: https://www.youtube.com/watch?v=N7-MueK2CX8&ab_channel=PortfolioCourses
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}       
        }

        //Enter the operator again if something is wrong
        while (1) //while true, check if user already input the right operator, if op is right ignore, else ask to input again
        {
            if (op == 'S' || op == 'L' || op == 'E' || op == 'C' || op == 'F')
            { 
                break;
            } 
            else
            {
                printf("Please enter a valid operation (S, L, E, C, F): "); //Double %% to print out the character
                scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {} 
            }
        }   

        //Unary Math switch case to do the actual math
        switch (op)
        {
            case 'S':   case 's':
                if (num1 >= 0)
                {
                    result = sqrt (num1);
                    flag = 1;
                }
                else 
                {
                    printf("Square root is not allowed for negative number\n");
                    result = 0;   
                    flag = 2; //IF FLAG = 2, re-enter num1                               
                }
                break;
            case 'L':   case 'l':
                if (num1 > 0)
                {
                    result = log (num1);
                    flag = 1;
                }
                else
                {
                    printf("Logarithm is not allowed for negative number\n");
                    result = 0;   
                    flag = 2; //IF FLAG = 2, re-enter num1                                  
                }
                break;
            case 'E':   case 'e':
                result = exp (num1);
                flag = 1;
                break;
            case 'C':   case 'c':
                result = ceil (num1);
                flag = 1;
                break;
            case 'F':   case 'f':
                result = floor (num1);
                flag = 1;
                break;
            default:
                printf("Please select the right operation (S, L, E, C, F)\n");
                result = 0; 
                flag = 0; //not sure if it reach here since already check for valid operator 
        }
    }
    //If the code reach this point, the input is valid so return the result and assign it to a variable
    return result;
}

float BinaryMathWithVariable (char var1, char var2, char op, float a, float b, float c, float d, float e)
{
    float num1 = 0, num2 = 0; 
    int check1 = 0, check2 = 0;
    int flag = 0;
    float result = 0;

    //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
    while (flag != 1)
    {
        //Invalid input check for num1 using while loop with flag
        flag = 0;                        
        while (flag != 1)
        {
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
                //Check if num1 is valid
                while (check1 != 1) //If the size of num1 is different to the size of float type, ask user to input again
                {
                    printf ("Please enter a decimal number for your first number: \n");
                    check1 = scanf ("%f", &num1);
                    //The 2 line of code below check for input buffering, found it HERE: https://www.youtube.com/watch?v=N7-MueK2CX8&ab_channel=PortfolioCourses
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}       
                }
                //Out of the check loop, set flag = 1;
                flag = 1;
            }
        }

        //Enter the operator again if something is wrong
        while (1) //while true, check if user already input the right operator, if op is right ignore, else ask to input again
        {
            if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == 'P' || op == 'X' || op == 'I')
            { 
                break;
            } 
            else
            {
                printf("Please enter a valid operation (+, -, *, /, %%, P, X, I): "); //Double %% to print out the character
                scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {} 
            }
        }

        //Invalid input check for num2 using while loop with flag
        flag = 0;                        
        while (flag != 1)
        {
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
                }
            }
            else
            {
                //Check if num1 is valid
                while (check2 != 1 || (op == '/' && num2 == 0) || (op == '%' && num2 == 0)) //If the size of num1 is different to the size of float type, ask user to input again
                {
                    printf ("Please enter a decimal number for your second number: \n");
                    check2 = scanf ("%f", &num2);
                    //The 2 line of code below check for input buffering, found it HERE: https://www.youtube.com/watch?v=N7-MueK2CX8&ab_channel=PortfolioCourses
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}       
                }
                //Out of the check loop, set flag = 1;
                flag = 1;
            }
        }

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
                    printf ("Division by zero is not allowed.\n");

                    //If the variable is zero, ask user to input another variable
                    printf ("Choose a variable that is not equal to zero for this operator or press any key to choose a number: \n");
                    scanf (" %c", &var2);
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}  

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
                    printf ("Remainder by zero is not allowed.\n");

                    //If the variable is zero, ask user to input another variable
                    printf ("Choose a variable that is not equal to zero for this operator or press any key to choose a number: \n");
                    scanf (" %c", &var2);
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}  

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
                printf("Please select the right operation (+, -, *, /, %%, P, X, I)\n");
                scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why
                result = 0.0;
                flag = 0;
        }                                
    } 
    //If the code reach this point, the input is valid so return the result and assign it to a variable
    return result;  
}

float UnaryMathWithVariable (char var1, char op, float a, float b, float c, float d, float e)
{
    float num1 = 0;
    int check1 = 0;
    int flag = 0;
    float result = 0;

    //While the flag is not 1, keep asking the user for input until the flag == 1, which means the inputs are correct
    flag = 0;                        
    while (flag != 1)
    {
        //Invalid input check for num1 using while loop with flag
        flag = 0;                        
        while (flag != 1)
        {
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
                //Check if num1 is valid, need to seperate the condition to remind user to enter the correct num1 for case 'S' and 'L'
                while (check1 != 1 || (op == 'S' && num1 < 0) || (op == 'L' && num1 <= 0)) //If the size of num1 is different to the size of float type, ask user to input again
                {
                    printf ("Please enter a decimal number for your first number: \n");
                    check1 = scanf ("%f", &num1);
                    //The 2 line of code below check for input buffering, found it HERE: https://www.youtube.com/watch?v=N7-MueK2CX8&ab_channel=PortfolioCourses
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}       
                }
                //Out of the check loop, set flag = 1;
                flag = 1;
            }
        }

        //Enter the operator again if something is wrong
        while (1) //while true, check if user already input the right operator, if op is right ignore, else ask to input again
        {
            if (op == 'S' || op == 'L' || op == 'E' || op == 'C' || op == 'F')
            { 
                break;
            } 
            else
            {
                printf("Please enter a valid operation (S, L, E, C, F): "); //Double %% to print out the character
                scanf(" %1c", &op); //Must have a space for %c or else it wont work, google it but still dont know why
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {} 
            }
        }   
        
        //Unary Math switch case to do the actual math
        switch (op)
        {
            case 'S':   case 's':
                if (num1 >= 0)
                {
                    result = sqrt (num1);
                    flag = 1;
                }
                else 
                {
                    printf("Square root is not allowed for negative number\n");

                    //If the variable is less than 0, ask user to input another variable
                    printf ("Choose a variable that is not equal to zero for this operator or press any key to choose a number: \n");
                    scanf (" %c", &var1);
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}  

                    result = 0; 
                    flag = 0;                       
                }
                break;
            case 'L':   case 'l':
                if (num1 > 0)
                {
                    result = log (num1);
                    flag = 0;
                }
                else
                {
                    printf("Logarithm is not allowed for negative number or number zero\n");

                    //If the variable is less than 0, ask user to input another variable
                    printf ("Choose a variable that is not equal to zero for this operator or press any key to choose a number: \n");
                    scanf (" %c", &var1);
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}  

                    result = 0; 
                    flag = 2;                                      
                }
                break;
            case 'E':   case 'e':
                result = exp (num1);
                flag = 1;
                break;
            case 'C':   case 'c':
                result = ceil (num1);
                flag = 1;
                break;
            case 'F':   case 'f':
                result = floor (num1);
                flag = 1;
                break;
            default:
                printf("Please select the right operation (S, L, E, C, F)\n");
                result = 0; 
                flag = 0; //not sure if it reach here since already check for valid operator 
        }        
    } 
    //If the code reach this point, the input is valid so return the result and assign it to a variable
    return result;  
}

void PrintVariable (float a,float b,float c,float d,float e)
{
    printf ("The variable A is: %.2f\n", a);
    printf ("The variable B is: %.2f\n", b);
    printf ("The variable C is: %.2f\n", c);
    printf ("The variable D is: %.2f\n", d);
    printf ("The variable E is: %.2f\n", e); 
}
