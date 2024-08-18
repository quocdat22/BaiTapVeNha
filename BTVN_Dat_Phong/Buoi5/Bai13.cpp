#include <stdio.h>

// Hàm đệ quy tính phần tử thứ n của cấp số nhân
double tinhUn(int n, double a, double q) {
   if (n == 1) {
       return a;  // Trường hợp cơ bản: U1 = a
   }
   else {
       return q * tinhUn(n - 1, a, q);
   }
}

int main() {
   int n;
   double a, q;

   printf("Nhập vào số hạng đầu tiên a: ");
   scanf("%lf", &a);
   printf("Nhập vào công bội q: ");
   scanf("%lf", &q);
   printf("Nhập vào vị trí n: ");
   scanf("%d", &n);

   if (n > 0) {
       double Un = tinhUn(n, a, q);
       printf("Phần tử thứ %d của cấp số nhân là: %lf\n", n, Un);
   }
   else {
       printf("Vui lòng nhập vị trí n là một số nguyên dương.\n");
   }

   return 0;
}
