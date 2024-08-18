#include <stdio.h>

// Hàm đệ quy tính x_n
int tinhXn(int n);

// Hàm đệ quy tính y_n
int tinhYn(int n) {
   if (n == 0) {
       return 0;  // y0 = 0
   }
   else {
       return 3 * tinhXn(n - 1) + 2 * tinhYn(n - 1);
   }
}

// Hàm đệ quy tính x_n
int tinhXn(int n) {
   if (n == 0) {
       return 1;  // x0 = 1
   }
   else {
       return tinhXn(n - 1) + tinhYn(n - 1);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n: ");
   scanf("%d", &n);

   if (n >= 0) {
       int xn = tinhXn(n);
       int yn = tinhYn(n);
       printf("x(%d) = %d\n", n, xn);
       printf("y(%d) = %d\n", n, yn);
   }
   else {
       printf("Vui lòng nhập số nguyên không âm.\n");
   }

   return 0;
}
