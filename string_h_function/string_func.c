#include <stdio.h>
#include <string.h>
 
int main() {
    char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%d", strlen(a));   // 26
    printf("%d", sizeof(a));   // 27

    char b[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%d", strlen(b));   // 26
    printf("%d", sizeof(b));   // 50

    // Create input for string
    char firstName[30];
    // Ask the user to input some text
    printf("Enter your first name: \n");
    // Get and save the text
    scanf("%s", firstName);
    // Output the text
    printf("Hello %s\n", firstName);

    //Combine 2 string
    char str1a[20] = "Hello ";
    char str2a[] = "World!";
    // Concatenate str2 to str1 (result is stored in str1)
    strcat(str1a, str2a);
    // Print str1
    printf("String 1 plus string 2 is: %s", str1a);    

    //Copy string from str1 to str2
    char str1b[20] = "Hello World!";
    char str2b[20];
    // Copy str1 to str2
    strcpy(str2b, str1b);
    // Print str2
    printf("String 2 new is: %s\n", str2b);    

    //Compare strings
    char str1c[] = "Hello";
    char str2c[] = "Hello";
    char str3c[] = "Hi";
    // Compare str1 and str2, and print the result
    printf("String compare: %d\n", strcmp(str1c, str2c));  // Returns 0 (the strings are equal)
    // Compare str1 and str3, and print the result
    printf("String compare: %d\n", strcmp(str1c, str3c));  // Returns -4 (the strings are not equal)   

    //strcat and strcopy
    char nameArr[100];          // User specified name
    char* greetingPtr = NULL;   // Pointer to output greeting and name
    // Prompt user to enter a name
    printf("Enter name: ");
    fgets(nameArr, 100, stdin);
    // Eliminate end-of-line char
    nameArr[strlen(nameArr) - 1] = '\0';
    // Dynamically allocate greeting
    // length of string nameArr + 6 for 'Hello ' + 1 '.' + 1 '\0'
    greetingPtr = (char*)malloc((strlen(nameArr) + 8) * sizeof(char));
    //greetingPtr = (char*)calloc((strlen(nameArr) + 8), sizeof(char));
    // Modify string, hello + user specified name
    strcpy(greetingPtr, "Hello ");
    strcat(greetingPtr, nameArr);
    strcat(greetingPtr, ".");
    // Output greeting and name
    printf("%s\n", greetingPtr);
    free(greetingPtr);

    return 0;
}