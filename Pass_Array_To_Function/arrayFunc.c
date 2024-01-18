// Online C compiler to run C program online
#include <stdio.h>

int SumArrayElements(int userVals[]) {
    int i = 0;
    for (i = 1; i < 5; ++i) 
    {
        userVals[i] = userVals[i] + userVals[i - 1];
    } 
    return userVals[i];
}

int SingleArrayElements(int e) {
    int ans;
    printf ("Value in the modify element in function: %d\n", ans = e*3);
    return ans;
}

int main() {
    // Write C code here
    int array[5]= {5,5,5,5,5};
    int sum = 0;
    printf("Sum of all array element: %d\n", sum = SumArrayElements(array));
    SingleArrayElements(array[3]);
    printf("Value of array element after the function: %d", array[3]);
    return 0;
}