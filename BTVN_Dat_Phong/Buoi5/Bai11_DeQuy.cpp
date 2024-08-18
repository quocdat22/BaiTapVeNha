#include <stdio.h>

// Hàm khử đệ quy tìm số Fibonacci lớn nhất nhỏ hơn n
int fibonacciLonNhatNhoHon(int n) {
   int a = 0, b = 1, c = a + b;

   while (c < n) {
       a = b;
       b = c;
       c = a + b;
   }

   return b;
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n: ");
   scanf("%d", &n);

   if (n > 1) {
       int ketQua = fibonacciLonNhatNhoHon(n);
       printf("Số Fibonacci lớn nhất nhỏ hơn %d là: %d\n", n, ketQua);
   }
   else {
       printf("Vui lòng nhập số nguyên dương lớn hơn 1.\n");
   }

   return 0;
}
