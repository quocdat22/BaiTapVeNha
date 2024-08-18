#include <stdio.h>

// Khai báo các hàm đệ quy để tính giá trị của A(n)
int tinhAn(int n);
int tinhAn2n(int n);
int tinhAn2nPlus1(int n);

// Hàm tính giá trị của A(n) dựa trên quy tắc đã cho
int tinhAn(int n) {
    if (n == 1) {
        return 1;  // Trường hợp cơ bản: A1 = 1
    }
    else if (n % 2 == 0) {
        // Trường hợp A2n = n + A(n/2) + 2
        return tinhAn2n(n / 2);
    }
    else {
        // Trường hợp A2n+1 = (n-1)/2^2 + A((n-1)/2) * A((n+1)/2) + 1
        return tinhAn2nPlus1((n - 1) / 2);
    }
}

// Hàm tính giá trị của A2n
int tinhAn2n(int n) {
    return n + tinhAn(n) + 2;
}

// Hàm tính giá trị của A2n+1
int tinhAn2nPlus1(int n) {
    int An = tinhAn(n);
    int AnPlus1 = tinhAn(n + 1);
    return n * n + An * AnPlus1 + 1;
}

int main() {
    int n;
    printf("Nhập vào số nguyên dương n: ");
    scanf("%d", &n);

    if (n >= 1) {
        int An = tinhAn(n);
        printf("Giá trị của A(%d) là: %d\n", n, An);
    }
    else {
        printf("Vui lòng nhập số nguyên dương n.\n");
    }

    return 0;
}
