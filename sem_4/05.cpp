#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2){
    if (b*b - 4*a*c > 0){
        double d = pow(b*b - 4*a*c, 0.5);
        *px1 = (-b + d) / 2 / a;
        *px2 = (-b - d) / 2 / a;
        return 2;
    }
    else if (b*b - 4*a*c == 0){
        *px1 = -b / 2 / a;
        return 1;
    }
    else
    return 0;
}

int main(){
    double px1 = 0;
    double px2 = 0;
    solve_quadratic(1, 4, 4, &px1, &px2);
    printf("%f", px1);
}