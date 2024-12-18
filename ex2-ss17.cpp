#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Hàm nh?p chu?i
void nhapchuoi(char *str) {
    printf("Nhap chuoi: ");
    getchar(); // Xóa ký t? xu?ng dòng còn sót trong b? d?m
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // Xóa ký t? xu?ng dòng cu?i chu?i
}

// Hàm in chu?i
void inchuoi(char *str) {
    printf("Chuoi: %s\n", str);
}

// Hàm d?m s? lu?ng ch? cái
int demchucai(char *str) {
    int dem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            dem++;
        }
    }
    return dem;
}

// Hàm d?m s? lu?ng ch? s?
int demchuso(char *str) {
    int dem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            dem++;
        }
    }
    return dem;
}

// Hàm d?m s? lu?ng ký t? d?c bi?t
int demkytudacbiet(char *str) {
    int tongkytu = strlen(str);
    return tongkytu - demchucai(str) - demchuso(str);
}

int main() {
    char chuoi[100] = ""; // Kh?i t?o chu?i r?ng
    int lua_chon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                nhapchuoi(chuoi);
                break;
            case 2:
                inchuoi(chuoi);
                break;
            case 3:
                printf("So luong chu cai: %d\n", demchucai(chuoi));
                break;
            case 4:
                printf("So luong chu so: %d\n", demchuso(chuoi));
                break;
            case 5:
                printf("So luong ky tu dac biet: %d\n", demkytudacbiet(chuoi));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (lua_chon != 6);

    return 0;
}

