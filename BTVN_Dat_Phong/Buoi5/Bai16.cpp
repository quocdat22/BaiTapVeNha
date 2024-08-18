#include <stdio.h>

// Hàm đệ quy tính giá trị của Y(n)
int tinhYn(int n) {
   if (n == 1) {
       return 1;  // Trường hợp cơ bản: Y1 = 1
   }
   else if (n == 2) {
       return 2;  // Trường hợp cơ bản: Y2 = 2
   }
   else if (n == 3) {
       return 3;  // Trường hợp cơ bản: Y3 = 3
   }
   else {
       return tinhYn(n - 1) + 2 * tinhYn(n - 2) + 3 * tinhYn(n - 3);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n (n >= 1): ");
   scanf("%d", &n);

   if (n >= 1) {
       int Yn = tinhYn(n);
       printf("Giá trị của Y(%d) là: %d\n", n, Yn);
   }
   else {
       printf("Vui lòng nhập số nguyên dương n (n >= 1).\n");
   }

   return 0;
}
