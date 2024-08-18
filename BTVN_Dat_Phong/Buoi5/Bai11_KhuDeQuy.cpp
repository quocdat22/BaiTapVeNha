#include <stdio.h>

// Hàm đệ quy tính số Fibonacci thứ k
int fibonacci(int k) {
   if (k == 0) {
       return 0;
   }
   else if (k == 1) {
       return 1;
   }
   else {
       return fibonacci(k - 1) + fibonacci(k - 2);
   }
}

// Hàm đệ quy tìm số Fibonacci lớn nhất nhỏ hơn n
int fibonacciLonNhatNhoHon(int n, int k) {
   int fib = fibonacci(k);
   if (fib >= n) {
       return fibonacci(k - 1);
   }
   else {
       return fibonacciLonNhatNhoHon(n, k + 1);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n: ");
   scanf("%d", &n);

   if (n > 1) {
       int ketQua = fibonacciLonNhatNhoHon(n, 0);
       printf("Số Fibonacci lớn nhất nhỏ hơn %d là: %d\n", n, ketQua);
   }
   else {
       printf("Vui lòng nhập số nguyên dương lớn hơn 1.\n");
   }

   return 0;
}
