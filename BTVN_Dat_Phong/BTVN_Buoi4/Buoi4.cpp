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
void splitName(char* fullName, char* lastName, char* firstName) {
    char* lastSpace = strrchr(fullName, ' ');
    if (lastSpace != NULL) {
        strcpy(firstName, lastSpace + 1);
        strncpy(lastName, fullName, lastSpace - fullName);
        lastName[lastSpace - fullName] = '\0';
    }
    else {
        strcpy(firstName, fullName);
        strcpy(lastName, "");
    }
}
void inputStudents(char students[][100], int* n) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    getchar();
    for (int i = 0; i < *n; i++) {
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        fgets(students[i], 100, stdin);
        students[i][strcspn(students[i], "\n")] = 0;
    }
}


void displayStudents(char students[][100], int n) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, students[i]);
    }
}


void bruteForceSearch(char* T, char* P) {
    int n = strlen(T);
    int m = strlen(P);
    int found = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (T[i + j] != P[j]) {
                break;
            }
        }
        if (j == m) {
            printf("Chuoi '%s' xuat hien o vi tri %d trong chuoi T.\n", P, i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Chuoi '%s' khong xuat hien trong chuoi T.\n", P);
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
        printf("5. Cat chuoi ho ten thanh ho lot va ten\n");
        printf("6. Nhap danh sach sinh vien va tim chuoi P trong T\n");
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
        case 5:
            printf("Nhap chuoi ho ten: ");
            fgets(s, 100, stdin);
            s[strcspn(s, "\n")] = 0;
            splitName(s, lastName, firstName);
            printf("Ho lot: %s\n", lastName);
            printf("Ten: %s\n", firstName);
            break;
        case 6:
            inputStudents(students, &n);
            displayStudents(students, n);
            printf("Nhap chuoi T: ");
            fgets(s, 100, stdin);
            s[strcspn(s, "\n")] = 0;
            printf("Nhap chuoi P: ");
            char P[100];
            fgets(P, 100, stdin);
            P[strcspn(P, "\n")] = 0;
            bruteForceSearch(s, P);
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