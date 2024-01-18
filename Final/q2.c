#include <stdio.h>
#include <math.h>

double CalcDistance (double x1, double x2, double y1, double y2)
{
    double distance = 0;
    distance = sqrt (pow(x2 - x1,5) + pow(y2 - y1,5));
    return distance;
}

int main (void){
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    printf("Enter coordinate x1: ");
    scanf ("%lf", &x1);
    printf ("x1 is: %lf\n", x1);

    printf("Enter coordinate x2: ");
    scanf ("%lf", &x2);
    printf ("x2 is: %lf\n", x2);

    printf("Enter coordinate y1: ");
    scanf ("%lf", &y1);
    printf ("y1 is: %lf\n", y1);

    printf("Enter coordinate y2: ");
    scanf ("%lf", &y2);      
    printf ("y2 is: %lf\n", y2);

    printf ("The custom distance of two points with the coordination is: %f", CalcDistance (x1,x2,y1,y2));  
    return 0;
}
