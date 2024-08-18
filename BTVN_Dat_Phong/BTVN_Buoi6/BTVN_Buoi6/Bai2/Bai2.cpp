#include <stdio.h>
#include <stdbool.h>


int tinhTichChan(int a[], int n) {
    if (n == 0) {
        return 1; 
    }

    int tich = tinhTichChan(a, n - 1);

    if (a[n - 1] % 2 == 0) {
        return tich * a[n - 1];
    }

    return tich;
}


bool chuaChuSo4(int n) {
    if (n == 0) {
        return false;
    }

    if (n % 10 == 4) {
        return true;
    }

    return chuaChuSo4(n / 10);
}


void xuatSoChuaChuSo4(int a[], int n) {
    if (n == 0) {
        return;
    }

    xuatSoChuaChuSo4(a, n - 1);

    if (chuaChuSo4(a[n - 1])) {
        printf("%d ", a[n - 1]);
    }
}


void hienThiMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Tinh tich cac so chan trong mang\n");
    printf("2. Xuat cac phan tu co chua chu so 4 trong mang\n");
    printf("0. Thoat chuong trinh\n");
    printf("Nhap lua chon: ");
}


int main() {
    int a[] = { 12, 44, 56, 14, 23, 41, 18, 40, 37 };
    int n = sizeof(a) / sizeof(a[0]);
    int luaChon;

    do {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Tich cac so chan trong mang: %d\n", tinhTichChan(a, n));
            break;
        case 2:
            printf("Cac phan tu co chua chu so 4 trong mang: ");
            xuatSoChuaChuSo4(a, n);
            printf("\n");
            break;
        case 0:
            printf("Chuong trinh ket thuc.\n");
            break;
        default:
            printf("Lua chon khong hop le! Vui long chon lai.\n");
            break;
        }
    } while (luaChon != 0);

    return 0;
}
