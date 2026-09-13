#include <stdio.h>

void intersect(double x1, double y1, double r1, double x2, double y2, double r2){
    double d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    double rr = (r1 + r2) * (r1 + r2);
    if ((d < rr + 2 * (r1 + r2) * 0.00001) && (d > rr - 2 * (r1 + r2) * 0.00001))
        printf("Touch");
    else if (d >= rr + 2 * (r1 + r2) * 0.00001)
        printf("Do not intersect");
    else if (d <= rr - 2 * (r1 + r2) * 0.00001)
        printf("Intersect");
}

int main(){
    double x1; double y1; double r1;
    double x2; double y2; double r2;
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    intersect(x1, y1, r1, x2, y2, r2);
}