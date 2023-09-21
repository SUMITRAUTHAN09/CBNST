#include <stdio.h>
#include <math.h>

#define max 0.00001

double f(double x) {
    return ((x * x * x) - 5 * x + 1);
}

int Check_IVt(double x0, double x1) {
    if (f(x0) * f(x1) < 0) {
        return 1;
    } else {
        return 0;
    }
}

void calculate_Roots(double x0, double x1) {
    int sumit = 2;
    double x2;
    while (1) {
        x2 = x1 - ((x1 - x0) / (f(x1) - f(x0))) * f(x1);

        printf("Root X%d: %lf\n", sumit, x2);

        sumit++;
        if (fabs(f(x2)) < max)
            break;

        x0 = x1;
        x1 = x2;
    }
}

int main() {
    double x1, x2;
    printf("Enter the value of x1 and x2: ");
    scanf("%lf %lf", &x1, &x2);
    int result = Check_IVt(x1, x2);
    if (result != 0) {
        printf("Root X1: %lf\n", x1);
        calculate_Roots(x1, x2);
    } else {
        printf("Enter valid numbers for which the function crosses the x-axis!\n");
    }

    return 0;
}
