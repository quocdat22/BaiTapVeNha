#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Hàm sắp xếp đường chéo phụ tăng dần/giảm dần
void sapXepDuongCheoPhu(int maTran[][100], int n) {
    int duongCheoPhu[100], soPhanTu = 0;
    for (int i = 0; i < n; i++) {
        duongCheoPhu[soPhanTu++] = maTran[i][n - i - 1];
    }

    // Sắp xếp tăng dần
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if (duongCheoPhu[i] > duongCheoPhu[j]) {
                int temp = duongCheoPhu[i];
                duongCheoPhu[i] = duongCheoPhu[j];
                duongCheoPhu[j] = temp;
            }
        }
    }

    // Gán lại vào ma trận
    for (int i = 0; i < n; i++) {
        maTran[i][n - i - 1] = duongCheoPhu[i];
    }
}

//in mang 2 chieu
void inMang2Chieu(int maTran[][100], int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

// Hàm sắp xếp các dòng của ma trận
void sapXepCacDong(int maTran[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && maTran[i][j] < maTran[i][k]) ||
                    (i % 2 != 0 && maTran[i][j] > maTran[i][k])) {
                    int temp = maTran[i][j];
                    maTran[i][j] = maTran[i][k];
                    maTran[i][k] = temp;
                }
            }
        }
    }
}
// Hàm sắp xếp các cột của ma trận
void sapXepCacCot(int maTran[][100], int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if ((j % 2 == 0 && maTran[i][j] > maTran[k][j]) ||
                    (j % 2 != 0 && maTran[i][j] < maTran[k][j])) {
                    int temp = maTran[i][j];
                    maTran[i][j] = maTran[k][j];
                    maTran[k][j] = temp;
                }
            }
        }
    }
}
// Hàm sắp xếp đường chéo chính và các đường chéo song song với nó
void sapXepDuongCheoChinhVaSongSong(int maTran[][100], int n) {
    int temp[100];
    for (int start = 0; start < n; start++) {
        int soPhanTu = 0;
        for (int i = 0; i < n - start; i++) {
            temp[soPhanTu++] = maTran[start + i][i];
        }
        // Sắp xếp đường chéo
        for (int i = 0; i < soPhanTu - 1; i++) {
            for (int j = i + 1; j < soPhanTu; j++) {
                if (temp[i] > temp[j]) {
                    int tmp = temp[i];
                    temp[i] = temp[j];
                    temp[j] = tmp;
                }
            }
        }
        // Gán lại vào ma trận
        for (int i = 0; i < n - start; i++) {
            maTran[start + i][i] = temp[i];
        }
    }

    for (int start = 1; start < n; start++) {
        int soPhanTu = 0;
        for (int i = 0; i < n - start; i++) {
            temp[soPhanTu++] = maTran[i][start + i];
        }
        // Sắp xếp đường chéo
        for (int i = 0; i < soPhanTu - 1; i++) {
            for (int j = i + 1; j < soPhanTu; j++) {
                if (temp[i] > temp[j]) {
                    int tmp = temp[i];
                    temp[i] = temp[j];
                    temp[j] = tmp;
                }
            }
        }
        // Gán lại vào ma trận
        for (int i = 0; i < n - start; i++) {
            maTran[i][start + i] = temp[i];
        }
    }
}


void diChuyenChanLe(int maTran[][100], int n) {
    int temp[10000];
    int chiSoChan = 0, chiSoLe = n * n - 1;

    // Duyệt qua toàn bộ ma trận và sắp xếp phần tử vào mảng tạm
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maTran[i][j] % 2 == 0) {
                temp[chiSoChan++] = maTran[i][j];
            }
            else {
                temp[chiSoLe--] = maTran[i][j];
            }
        }
    }

    // Gán lại các giá trị từ mảng tạm vào ma trận, phần chẵn trước, phần lẻ sau
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (index <= chiSoLe) {
                maTran[i][j] = temp[index++];
            }
            else {
                maTran[i][j] = temp[chiSoChan++];
            }
        }
    }
}


int main() {
    int maTran[100][100], n = 5;

    // Khởi tạo giá trị ngẫu nhiên cho ma trận
    srand(time(NULL));
    printf("Ma tran ngau nhien 5x5:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maTran[i][j] = rand() % 100;
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }

    // Gọi các hàm xử lý ma trận
   /* sapXepDuongCheoPhu(maTran, n);
    inMang2Chieu(maTran, n);*/

    /*sapXepCacDong(maTran, n);
    printf("Ma tran sau khi sap xep cac dong:\n");
    inMang2Chieu(maTran, n);*/

    /*sapXepCacCot(maTran, n);
    printf("Ma tran sau khi sap xep cac cot:\n");
    inMang2Chieu(maTran, n);*/

    /*sapXepDuongCheoChinhVaSongSong(maTran, n);
    printf("Ma tran sau khi sap xep duong cheo chinh va song song:\n");
    inMang2Chieu(maTran, n);*/

    diChuyenChanLe(maTran, n);
    printf("Ma tran sau khi di chuyen cac phan tu chan len tren, le xuong duoi:\n");
    inMang2Chieu(maTran, n);

    

    return 0;
}