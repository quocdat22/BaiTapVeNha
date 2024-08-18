#include <stdio.h>

// Hàm đệ quy tính giá trị của U(n)
int tinhUn(int n) {
   if (n < 6) {
       return n;  // Khi n < 6, U(n) = n
   }
   else {
       return tinhUn(n - 5) + tinhUn(n - 4) + tinhUn(n - 3) + tinhUn(n - 2) + tinhUn(n - 1);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n: ");
   scanf("%d", &n);

   if (n > 0) {
       int Un = tinhUn(n);
       printf("Giá trị của U(%d) là: %d\n", n, Un);
   }
   else {
       printf("Vui lòng nhập số nguyên dương.\n");
   }

   return 0;
}
