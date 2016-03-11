#include <fcntl.h>
#include <math.h>
#include <stdio.h>

#define _USE_MATH_DEFINES

float f(float); 

float a = 1;
float b = M_PI;
float x;
float h;
float sum;
int n;
int i;

int main() {

    FILE *fp;
    fp=fopen("trapezium.txt", "w"); 


    float num_rectangles;
    printf("Enter num rectangles: "); 
    scanf("%f", &n); 

    h = (b-a) / n;  // step

    sum = (0.5 * h) * (f(a) + f(b));

    fprintf(fp, "%f\n", sum); 

    for (i=1; i<n; i++) {
        sum = sum + h * f(a + (i * h));
        fprintf(fp, "%f\n", sum); 
    }
    fprintf(fp, "integral value: %f\n", sum); 

    fclose(fp); 

    return 0;
}

float f(float x) {
    float value;
    value = 2*(x*x)+x;
    return value;
}
