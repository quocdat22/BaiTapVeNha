#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int isDigitsOnly(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int choice;
    char s[100], lastName[100], firstName[100];
    char students[100][100];
    int n;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Kiem tra chuoi s co toan ky so hay khong\n");
 
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("Nhap chuoi s: ");
            fgets(s, 100, stdin);
            s[strcspn(s, "\n")] = 0;
            if (isDigitsOnly(s)) {
                printf("Chuoi s co toan ky so.\n");
            }
            else {
                printf("Chuoi s khong co toan ky so.\n");
            }
            break;

        

        case 0:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 0);

    return 0;
}