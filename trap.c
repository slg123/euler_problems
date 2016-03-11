#include <fcntl.h>
#include <math.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#define max_in 501
#define vmin 0.0
#define vmax 1.0
#define ME 2.7182818284590453454E0

int main() {

    FILE *output;
    output=fopen("integral.dat", "w"); 

    float result;
    float trapez(int no, float min, float max); 
    float f(float); 

    int i;
    for (i=3; i<=max_in; i+=2) {
        result = trapez(i, vmin, vmax);
        fprintf(output, "%i\t%e\t\n", i, fabs(result-1+1/ME)); 
    }

    fclose(output); 

    return 0;
}

float f(float x) {
    return (exp(-x));
}

float trapez(int no, float min, float max) {
    int n;
    float interval, sum=0.0, x; 

    interval = ((max-min) / (no-1)); 
    for (n=2; n<no; n++) {
        x = interval * (n-1); 
        sum += f(x)*interval;
    }
    sum += 0.5 * (f(min) + f(max)) * interval; 

    return sum;
}

