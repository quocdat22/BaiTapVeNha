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

//Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó.
int demSoLuongPhanTuChuaChuSo2(int a[][100], int m, int n) {
	int dem = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int temp = a[i][j];
			while (temp != 0) {
				int chuSo = temp % 10;
				if (chuSo == 2) {
					dem++;
					break;
				}
				temp /= 10;
			}
		}
	}
	return dem;
}

//Xuất các phần tử cực tiểu của ma trận.
void xuatCacPhanTuCucTieu(int a[][100], int m, int n) {
	printf("Cac phan tu cuc tieu trong ma tran\n");
	printf("Vi tri (Dong-Cot)\t Gia tri\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int current = a[i][j];
			int isMin = 1;

			if (i > 0 && a[i - 1][j] <= current) isMin = 0;
			if (i < m - 1 && a[i + 1][j] <= current) isMin = 0;
			if (j > 0 && a[i][j - 1] <= current) isMin = 0;
			if (j < n - 1 && a[i][j + 1] <= current) isMin = 0;

			if (isMin) {
				printf("%2d-%d\t\t\t%5d\n", i, j, current);
			}
		}
	}
	printf("\n");
}

//Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần.
void sapXepDongTangDanBai3(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void sapXepDongGiamDanBai3(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void sapXepMaTranLeTangChanGiam(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			// Dòng có chỉ số chẵn (bắt đầu từ 0) -> sắp xếp giảm dần
			sapXepDongGiamDanBai3(a[i], n);
		}
		else {
			// Dòng có chỉ số lẻ -> sắp xếp tăng dần
			sapXepDongTangDanBai3(a[i], n);
		}
	}
}

void sapXepMaTranLeGiamChanTang(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		if (i % 2 != 0) {
			// Dòng có chỉ số chẵn (bắt đầu từ 0) -> sắp xếp giảm dần
			sapXepDongGiamDanBai3(a[i], n);
		}
		else {
			// Dòng có chỉ số lẻ -> sắp xếp tăng dần
			sapXepDongTangDanBai3(a[i], n);
		}
	}
}

int kiemTraZiczacCot(int a[][100], int m, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m - 1; i++) {
			if (a[i][j] < a[i + 1][j]) {
				return 0; // Không thỏa mãn điều kiện giảm dần
			}
		}
	}
	return 1; // Thỏa mãn điều kiện giảm dần
}


int kiemTraZiczacDong(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] < a[i][j + 1]) {
				return 0; // Không thỏa mãn điều kiện giảm dần theo dòng
			}
		}
	}
	return 1; // Thỏa mãn điều kiện giảm dần theo dòng
}

//Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void lietKeCacDongChuaToanGiaTriChan(int a[][100], int m, int n) {
	printf("Cac dong chua toan gia tri chan la:");
	for (int i = 0; i < m; i++) {
		int flag = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			printf("%5d", i);
		}
	}
}


//Liệt kê các dòng chứa giá trị giảm dần
void lietKeCacDongChuaGiaTriGiamDan(int a[][100], int m, int n) {
	printf("Cac dong chua gia tri giam dan la:");
	for (int i = 0; i < m; i++) {
		int flag = 1;
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] < a[i][j + 1]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			printf("%5d", i);
		}
	}
}

//Tìm giá trị xuất hiện nhiều nhất trong ma trận
int timGiaTriXuatHienNhieuNhat(int a[][100], int m, int n) {
	int maxCount = 0;
	int maxValue = a[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int current = a[i][j];
			int count = 1;
			for (int k = i; k < m; k++) {
				for (int l = 0; l < n; l++) {
					if (k == i && l <= j) continue;
					if (a[k][l] == current) {
						count++;
					}
				}
			}
			if (count > maxCount) {
				maxCount = count;
				maxValue = current;
			}
		}
	}
	return maxValue;
}

//Tìm các chữ số xuất hiện nhiều nhất trong ma trận
void demChuSo(int a[][100], int m, int n, int demChuSo[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int temp = a[i][j];
			if (temp == 0) {
				demChuSo[0]++;
			}
			while (temp != 0) {
				int chuSo = temp % 10;
				demChuSo[chuSo]++;
				temp /= 10;
			}
		}
	}
}
// Hàm tìm chữ số xuất hiện nhiều nhất
int timChuSoXuatHienNhieuNhat(int demChuSo[]) {
	int maxChuSo = 0;
	int maxLanXuatHien = demChuSo[0];
	for (int i = 1; i < 10; i++) {
		if (demChuSo[i] > maxLanXuatHien) {
			maxChuSo = i;
			maxLanXuatHien = demChuSo[i];
		}
	}
	return maxChuSo;
}

//Liệt kê các cột có tổng nhỏ nhất trong ma trận
void lietKeCotCoTongNhoNhat(int a[][100], int m, int n) {
	int sum[100] = { 0 };
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			sum[j] += a[i][j];
		}
	}
	int minSum = sum[0];
	for (int j = 1; j < n; j++) {
		if (sum[j] < minSum) {
			minSum = sum[j];
		}
	}
	printf("Cac cot co tong nho nhat la:");
	for (int j = 0; j < n; j++) {
		if (sum[j] == minSum) {
			printf("%5d", j);
		}
	}
}

//Hoán vị hai cột i và j trong ma trận
void hoanViHaiCot(int a[][100], int m, int n, int i, int j) {
	for (int k = 0; k < m; k++) {
		int temp = a[k][i];
		a[k][i] = a[k][j];
		a[k][j] = temp;
	}
}

//Hoán vị hai dòng k và l trong ma trận
void hoanViHaiDong(int a[][100], int m, int n, int k, int l) {
	for (int j = 0; j < n; j++) {
		int temp = a[k][j];
		a[k][j] = a[l][j];
		a[l][j] = temp;
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


	printf("\nPhan tu lon nhat tren bien cua ma tran la: %d", timMaxBien(a, m, n));

	printf("\nSo luong phan tu chua chu so 2 trong ma tran la: %d", demSoLuongPhanTuChuaChuSo2(a, m, n));

	xuatCacPhanTuCucTieu(a, m, n);

	sapXepDongTangDanBai3(a[1], n);

	printf("Mang 2 chieu sau khi sap xep theo yeu cau: \n");
	xuatMang2ChieuBai3(a, m, n);

	
	sapXepMaTranLeTangChanGiam(a, m, n);
	printf("Mang 2 chieu sau khi sap xep theo yeu cau: \n");
	xuatMang2ChieuBai3(a, m, n);

	sapXepMaTranLeGiamChanTang(a, m, n);
	printf("Mang 2 chieu sau khi sap xep theo yeu cau: \n");
	xuatMang2ChieuBai3(a, m, n);

	if (kiemTraZiczacCot(a, m, n) == 1) {
		printf("Ma tran zicic");
	}
	else {
		printf("Ma tran khong zicic");
	}

	lietKeCacDongChuaToanGiaTriChan(a, m, n);
		
	lietKeCacDongChuaGiaTriGiamDan(a, m, n);

	printf("Gia tri xuat hien nhieu nhat trong ma tran la: %d", timGiaTriXuatHienNhieuNhat(a, m, n));

	// Đếm chữ số
	int demChuSoC[10] = { 0 }; // Mảng đếm chữ số từ 0 đến 9
	demChuSo(a, m, n, demChuSoC);
	// Tìm chữ số xuất hiện nhiều nhất
	int chuSoNhieuNhat = timChuSoXuatHienNhieuNhat(demChuSoC);
	printf("Chu so xuat hien nhieu nhat trong ma tran la: %d\n", chuSoNhieuNhat);


	//14
	hoanViHaiDong(a, m, n, 1, 2);
	printf("\nMang 2 chieu sau khi hoan vi dong 1 va 2: \n");
	xuatMang2ChieuBai3(a, m, n);

	//13
	hoanViHaiCot(a, m, n, 1, 2);
	printf("\nMang 2 chieu sau khi hoan vi cot 1 va 2: \n");
	xuatMang2ChieuBai3(a, m, n);

	return;
}