#include <stdio.h>

// Khai báo hàm để tránh lỗi "identifier not found"
int tinhAn(int n);
int tinhTongAn(int n);

// Hàm đệ quy tính tổng từ A1 đến A(n-1)
int tinhTongAn(int n) {
   if (n == 1) {
       return 1;  // Trường hợp cơ bản: A1 = 1
   }
   else {
       return tinhAn(n - 1) + tinhTongAn(n - 1);
   }
}

// Hàm đệ quy tính giá trị của An
int tinhAn(int n) {
   if (n == 1) {
       return 1;  // Trường hợp cơ bản: A1 = 1
   }
   else {
       return n * tinhTongAn(n);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n: ");
   scanf("%d", &n);

   if (n > 0) {
       int An = tinhAn(n);
       printf("Giá trị của A(%d) là: %d\n", n, An);
   }
   else {
       printf("Vui lòng nhập số nguyên dương.\n");
   }

   return 0;
}
