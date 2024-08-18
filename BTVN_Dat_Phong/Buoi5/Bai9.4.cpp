#include <stdio.h>
#include <math.h>

// Hàm tính giai thừa
long long giaiThua(int n) {
   if (n == 1 || n == 0) {
       return 1;
   }
   else {
       return n * giaiThua(n - 1);
   }
}

// Hàm đệ quy tính S(n)
double tinhS(int n) {
   if (n == 1) {
       return (1.0 + 2) / giaiThua(2);  // Trường hợp cơ bản
   }
   else {
       int tuSo = 2 * n - 1 + 2 * n;
       double mauSo = giaiThua(2 * n);
       return pow(-1, n - 1) * (tuSo / mauSo) + tinhS(n - 1);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n: ");
   scanf("%d", &n);

   if (n > 0) {
       double ketQua = tinhS(n);
       printf("S(%d) = %lf\n", n, ketQua);
   }
   else {
       printf("Vui lòng nhập số nguyên dương.\n");
   }

   return 0;
}
