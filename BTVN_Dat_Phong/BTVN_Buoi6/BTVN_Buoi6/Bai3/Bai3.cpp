#include <stdio.h>
#include <string.h>

#define MAX 100


typedef struct {
    char maThuoc[6];
    char tenThuoc[21];
    char nhaSanXuat[21];
    char dangThuoc[11];
    float donGia;
    char congDung[51];
} Thuoc;


void nhapThongTinThuoc(Thuoc* thuoc) {
    printf("Nhap ma thuoc (5 ky tu): ");
    scanf("%s", thuoc->maThuoc);

    printf("Nhap ten thuoc (20 ky tu): ");
    scanf(" %[^\n]", thuoc->tenThuoc);

    printf("Nhap nha san xuat (20 ky tu): ");
    scanf(" %[^\n]", thuoc->nhaSanXuat);

    do {
        printf("Nhap dang thuoc (vien/nuoc): ");
        scanf("%s", thuoc->dangThuoc);
    } while (strcmp(thuoc->dangThuoc, "vien") != 0 && strcmp(thuoc->dangThuoc, "nuoc") != 0);

    printf("Nhap don gia: ");
    scanf("%f", &thuoc->donGia);

    printf("Nhap cong dung (50 ky tu): ");
    scanf(" %[^\n]", thuoc->congDung);
}


void xuatThongTinThuoc(Thuoc thuoc) {
    printf("\nMa thuoc: %s", thuoc.maThuoc);
    printf("\nTen thuoc: %s", thuoc.tenThuoc);
    printf("\nNha san xuat: %s", thuoc.nhaSanXuat);
    printf("\nDang thuoc: %s", thuoc.dangThuoc);
    printf("\nDon gia: %.2f", thuoc.donGia);
    printf("\nCong dung: %s\n", thuoc.congDung);
}


void nhapDanhSachThuoc(Thuoc ds[], int* n) {
    printf("Nhap so luong thuoc: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin thuoc thu %d:\n", i + 1);
        nhapThongTinThuoc(&ds[i]);
    }
}


void xuatDanhSachThuoc(Thuoc ds[], int n) {
    printf("\nDanh sach thuoc:\n");
    for (int i = 0; i < n; i++) {
        xuatThongTinThuoc(ds[i]);
    }
}


void hoanDoiThuoc(Thuoc* a, Thuoc* b) {
    Thuoc temp = *a;
    *a = *b;
    *b = temp;
}


void sapXepTheoMaThuoc(Thuoc ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ds[i].maThuoc, ds[j].maThuoc) > 0) {
                hoanDoiThuoc(&ds[i], &ds[j]);
            }
        }
    }
    printf("\nDanh sach thuoc sau khi sap xep theo ma thuoc:\n");
    xuatDanhSachThuoc(ds, n);
}


int binarySearch(Thuoc ds[], int n, char* maTim) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strncmp(ds[mid].maThuoc, maTim, 3) == 0) {
            return mid;
        }
        else if (strncmp(ds[mid].maThuoc, maTim, 3) > 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1; 
}


void hienThiMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Nhap danh sach thuoc\n");
    printf("2. Xuat danh sach thuoc\n");
    printf("3. Sap xep danh sach thuoc theo ma\n");
    printf("4. Tim thuoc co ma so bat dau bang 'T01'\n");
    printf("0. Thoat chuong trinh\n");
    printf("Nhap lua chon: ");
}


int main() {
    Thuoc ds[MAX];
    int n = 0, luaChon;

    do {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            nhapDanhSachThuoc(ds, &n);
            break;
        case 2:
            xuatDanhSachThuoc(ds, n);
            break;
        case 3:
            sapXepTheoMaThuoc(ds, n);
            break;
        case 4: {
            char maTim[] = "T01";
            int ketQua = binarySearch(ds, n, maTim);
            if (ketQua != -1) {
                printf("\nTim thay thuoc co ma bat dau bang 'T01':\n");
                xuatThongTinThuoc(ds[ketQua]);
            }
            else {
                printf("\nKhong tim thay thuoc co ma bat dau bang 'T01'.\n");
            }
            break;
        }
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
