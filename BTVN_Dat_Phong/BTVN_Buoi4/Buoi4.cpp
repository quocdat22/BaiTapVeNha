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
void capitalizeWords(char* s) {
    int inWord = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isspace(s[i])) {
            inWord = 0;
        }
        else {
            if (!inWord) {
                s[i] = toupper(s[i]);
                inWord = 1;
            }
            else {
                s[i] = tolower(s[i]);
            }
        }
    }
}
void trimSpaces(char* s) {
    int n = strlen(s);
    int i, x = 0;
    for (i = 0; i < n; i++) {
        if (!isspace(s[i]) || (i > 0 && !isspace(s[i - 1]))) {
            s[x++] = s[i];
        }
    }
    if (x > 0 && isspace(s[x - 1])) x--;
    s[x] = '\0';
}
int findName(char* fullName, char* name) {
    if (strstr(fullName, name) != NULL) {
        printf("Ten '%s' co ton tai trong chuoi '%s'.\n", name, fullName);
        return 1;
    }
    else {
        printf("Ten '%s' khong ton tai trong chuoi '%s'.\n", name, fullName);
        return 0;
    }
}
int main() {
    int choice;
    char s[100], lastName[100], firstName[100];
    char students[100][100];
    int n;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Kiem tra chuoi s co toan ky so hay khong\n");
        printf("2. Doi ki tu dau cua moi tu thanh chu in hoa\n");
        printf("3. Xoa khoang trang thua trong chuoi\n");
        printf("4. Tim kiem ten trong chuoi ho ten\n");
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

        
        case 2:
            printf("Nhap chuoi s: ");
            fgets(s, 100, stdin);
            s[strcspn(s, "\n")] = 0;
            capitalizeWords(s);
            printf("Chuoi sau khi doi ki tu: %s\n", s);
            break;
        case 3:
            printf("Nhap chuoi s: ");
            fgets(s, 100, stdin);
            s[strcspn(s, "\n")] = 0;
            trimSpaces(s);
            printf("Chuoi sau khi xoa khoang trang thua: %s\n", s);
            break;
        case 4:
            printf("Nhap chuoi ho ten: ");
            fgets(s, 100, stdin);
            s[strcspn(s, "\n")] = 0;
            printf("Nhap ten can tim: ");
            char name[50];
            fgets(name, 50, stdin);
            name[strcspn(name, "\n")] = 0;
            findName(s, name);
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