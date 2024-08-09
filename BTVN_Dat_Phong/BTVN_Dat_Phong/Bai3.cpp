#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void khoiTaoMang2ChieuBai3(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (100 + 1);
		}
	}
}
void xuatMang2ChieuBai3(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

//Xuất giá trị số cột chỉ chứa số lẻ
void xuatCotChiChuaSoLe(int a[][100], int m, int n) {
	printf("Cac cot chi chua so le la:");
	for (int j = 0; j < n; j++) {
		int flag = 0;
		for (int i = 0; i < m; i++) {
			if (a[i][j] % 2 == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			printf("%5d", j);
		}
	}
}

void bai3() {
	srand(time(NULL));
	int m = 5;
	int n = 5;
	int a[100][100];

	khoiTaoMang2ChieuBai3(a, m, n);

	printf("Mang 2 chieu duoc khoi tao ngau nhien: \n");
	xuatMang2ChieuBai3(a, m, n);

	xuatCotChiChuaSoLe(a, m, n);

	return;
}