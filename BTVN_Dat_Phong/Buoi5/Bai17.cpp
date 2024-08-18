    #include <stdio.h>

// Hàm đệ quy tính giá trị của X(n)
int tinhXn(int n) {
   if (n == 1) {
       return 1;  // Trường hợp cơ bản: X1 = 1
   }
   else if (n == 2) {
       return 1;  // Trường hợp cơ bản: X2 = 1
   }
   else {
       // Trường hợp n >= 3: Xn = X(n-1) + (n-1) * X(n-2)
       return tinhXn(n - 1) + (n - 1) * tinhXn(n - 2);
   }
}

int main() {
   int n;
   printf("Nhập vào số nguyên dương n (n >= 1): ");
   scanf("%d", &n);

   if (n >= 1) {
       int Xn = tinhXn(n);
       printf("Giá trị của X(%d) là: %d\n", n, Xn);
   }
   else {
       printf("Vui lòng nhập số nguyên dương n (n >= 1).\n");
   }

   return 0;
}
