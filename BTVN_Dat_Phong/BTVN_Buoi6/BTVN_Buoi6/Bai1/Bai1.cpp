#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;
    char description[100];
    void (*func)();
} BaiToan;


void baiToan1() {
    printf("bai tap 1\n");
    
}

void baiToan2() {
    printf("bai tap 2\n");
   
}

void baiToan3() {
    printf("bai tap 3\n");
    
}


void hienThiDanhSach(BaiToan* danhSach, int soLuong) {
    printf("Danh sach cac bai tap:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("%d. %s\n", danhSach[i].id, danhSach[i].description);
    }
}


void xuLyNgoaiLe() {
    printf("Lua chon khong hop le! Vui long chon lai.\n");
}


int main() {
    
    BaiToan danhSachBaiToan[] = {
        {1, "Bai tap 1", baiToan1},
        {2, "Bai tap 2", baiToan2},
        {3, "Bai tap 3", baiToan3}
    };

    int soLuongBaiToan = sizeof(danhSachBaiToan) / sizeof(BaiToan);
    int luaChon;

    while (1) {
        hienThiDanhSach(danhSachBaiToan, soLuongBaiToan);
        printf("Nhap lua chon cua ban (0 de thoat): ");
        if (scanf("%d", &luaChon) != 1) {
            while (getchar() != '\n'); 
            xuLyNgoaiLe();
            continue;
        }

        if (luaChon == 0) {
            break;
        }

        int hopLe = 0;
        for (int i = 0; i < soLuongBaiToan; i++) {
            if (luaChon == danhSachBaiToan[i].id) {
                danhSachBaiToan[i].func();
                hopLe = 1;
                break;
            }
        }

        if (!hopLe) {
            xuLyNgoaiLe();
        }

        printf("\n");
    }

    printf("Chuong trinh ket thuc.\n");
    return 0;
}
