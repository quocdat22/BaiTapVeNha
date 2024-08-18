#include <stdio.h>

double recursiveSum(int n) {
    if (n == 1) {
        return 1.0 / (1 * 2 * 3);
    }
    else {
        return 1.0 / (n * (n + 1) * (n + 2)) + recursiveSum(n - 1);
    }
}

int main() {
    int n;
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    if (n > 0) {
        double result = recursiveSum(n);
        printf("Recursive S(%d) = %lf\n", n, result);
    }
    else {
        printf("Please enter a positive integer.\n");
    }

    return 0;
}
