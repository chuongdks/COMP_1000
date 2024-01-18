// Online C compiler to run C program online

#include <stdio.h>
#include <math.h>
int main() {    
    // Write C code here    
    float p = 0.0, r = 0.05, a = 0;    
    int n;    
    printf ("Enter your saving money:\n");    
    scanf ("%f", &p);    
    printf ("Enter your year:\n");    
    scanf ("%d", &n);        
    for (int i = 1; i <= n; i++)
    {        
        a = p * pow (1 + r, i);        
        printf ("%5s%21s\n", "Year", "Profit");        
        printf ("%3d.%22.2f\n", i, a);
    }
    return 0;
}