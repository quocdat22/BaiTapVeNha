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

// Hàm in các số Fibonacci trong khoảng từ m đến n
void inSoFibonacci(int m, int n) {
   int i = 0;
   int fib;

   while (1) {
       fib = fibonacci(i);
       if (fib > n) {
           break;
       }
       if (fib >= m) {
           printf("%d ", fib);
       }
       i++;
   }
   printf("\n");
}

int main() {
   int m, n;

   printf("Nhập vào số m: ");
   scanf("%d", &m);
   printf("Nhập vào số n: ");
   scanf("%d", &n);

   if (m > n) {
       printf("Giá trị m phải nhỏ hơn hoặc bằng n.\n");
   }
   else {
       printf("Các số Fibonacci trong khoảng từ %d đến %d là: ", m, n);
       inSoFibonacci(m, n);
   }

   return 0;
}
