#define step 1e-2
#define eps 1e-10
#include <math.h>
#include <stdio.h>

double gamma(double x){
    double t = step;
    double ds = 0;
    double sum = 0;
    do
    {
       ds = pow(t, x - 1) * pow(M_E, -t) * step;
       t += step;
       sum += ds;
    }
    while (ds > eps && t < 200.0);
    return sum;
}

int main() {
    printf("%lf", gamma(2.5));
}