#include <stdio.h>

// Hàm đệ quy tính giá trị của x(n)
int tinhXn(int n) {
   if (n == 0) {
       return 1;  // Trường hợp cơ bản: x0 = 1
   }
   else if (n == 1) {
       return 2;  // Trường hợp cơ bản: x1 = 2
   }
   else {
       int tong = 0;
       for (int i = 0; i < n; i++) {
           tong += (n - i) * tinhXn(i);
       }
       return tong;
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên không âm n: ");
   scanf("%d", &n);

   if (n >= 0) {
       int Xn = tinhXn(n);
       printf("Giá trị của x(%d) là: %d\n", n, Xn);
   }
   else {
       printf("Vui lòng nhập số nguyên không âm n.\n");
   }

   return 0;
}
