    #include <stdio.h>

int tinhTongBinhPhuong(int n) {
   if (n == 1) {
       return 1;  // Trường hợp cơ bản
   }
   else {
       return n * n + tinhTongBinhPhuong(n - 1);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n: ");
   scanf("%d", &n);

   if (n > 0) {
       int ketQua = tinhTongBinhPhuong(n);
       printf("S(%d) = %d\n", n, ketQua);
   }
   else {
       printf("Vui lòng nhập số nguyên dương.\n");
   }

   return 0;
}
