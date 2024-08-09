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

//Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
int timMaxBien(int a[][100], int m, int n) {
	int max = a[0][0];
	for (int j = 1; j < n; j++) {
		if (a[0][j] > max) {
			max = a[0][j];
		}
	}
	for (int i = 1; i < m; i++) {
		if (a[i][n - 1] > max) {
			max = a[i][n - 1];
		}
	}
	for (int j = n - 2; j >= 0; j--) {
		if (a[m - 1][j] > max) {
			max = a[m - 1][j];
		}
	}
	for (int i = m - 2; i >= 0; i--) {
		if (a[i][0] > max) {
			max = a[i][0];
		}
	}
	return max;
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


	printf("\nPhan tu lon nhat tren bien cua ma tran la: %d", timMaxBien(a, m, n));


	return;
}