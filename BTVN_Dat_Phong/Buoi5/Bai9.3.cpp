#include <stdio.h>

// Hàm tính tổng từ 1 đến n
int tinhTong(int n) {
   if (n == 1) {
       return 1;
   }
   else {
       return n + tinhTong(n - 1);
   }
}

// Hàm đệ quy tính S(n)
int tinhS(int n) {
   if (n == 1) {
       return 1;  // Trường hợp cơ bản
   }
   else {
       return tinhTong(n) + tinhS(n - 1);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n: ");
   scanf("%d", &n);

   if (n > 0) {
       int ketQua = tinhS(n);
       printf("S(%d) = %d\n", n, ketQua);
   }
   else {
       printf("Vui lòng nhập số nguyên dương.\n");
   }

   return 0;
}
