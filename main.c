#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maSinhVien[10];
    char tenSinhVien[50];
    char soDienThoai[20];
} thongTinSinhVien;

void themSinhVien(thongTinSinhVien sinhVien[], int *p) {
    while (1) {
        printf("Nhập mã sinh viên (mã sinh viên phải có 5 ký tự): \n");
        scanf("%s", sinhVien[*p].maSinhVien);
        if (strlen(sinhVien[*p].maSinhVien) != 5) {
            printf("Lỗi !!! Bạn phải nhập đủ 5 ký tự !!! \n");
            printf("Vui lòng nhập lại !!!\n");
        } else
            break;
    }
    printf("Nhập tên sinh viên: \n");
    fgetc(stdin);
    scanf("%[^\n]", sinhVien[*p].tenSinhVien);
    printf("Nhập số điện thoại: \n");
    fgetc(stdin);
    scanf("%[0-9]", sinhVien[*p].soDienThoai);
    *p += 1;
}

void hienThi(thongTinSinhVien sinhVien[], int *p) {

    printf("%-10s%-20s%-10s%-20s%-10s%-20s\n", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int i = 0; i < *p; ++i) {
        printf("%-10s%-18s%-10s%-18s%-10s%-18s\n", "", sinhVien[i].maSinhVien, "|", sinhVien[i].tenSinhVien, "|",
               sinhVien[i].soDienThoai);
    }
}

void luuDanhSach(thongTinSinhVien sinhVien[], int *p) {
    FILE *f = fopen("danhsachsinhvien.txt", "w+");
    fprintf(f, "%-10s%-20s%-10s%-20s%-10s%-20s\r\n", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int i = 0; i < *p; i++) {
        fprintf(f, "%-10s%-18s%-10s%-18s%-10s%-18s\r\n", "", sinhVien[i].maSinhVien, "|", sinhVien[i].tenSinhVien, "|",
                sinhVien[i].soDienThoai);
    }
    fclose(f);
}

void docDanhSach() {
    FILE *f = fopen("danhsachsinhvien.txt", "r");
    printf("Đọc dữ liệu từ file\n");
    char buffer[255];
    while (fgets(buffer, 255, f) != NULL) {
        printf("%s", buffer);
    }
    fclose(f);
}

int main() {
    thongTinSinhVien sinhVien[10] = {};
    int i = 0;
    int *p;
    p = &i;
    int luachon;
    while (1) {
        printf("----------MENU----------\n");
        printf("1. Thêm mới sinh viên.\n");
        printf("2. Hiển thị danh sách sinh viên.\n");
        printf("3. Lưu danh sách sinh viên ra file.\n");
        printf("4. Đọc danh sách sinh viên từ file.\n");
        printf("5. Thoát chương trình.\n");
        printf("Nhập lựa chọn của người dùng (1-5): \n");
        scanf("%d", &luachon);
        switch (luachon) {
            case 1:
                if (*p == 10) {
                    printf("Danh sách sinh viên đã đầy!!!\n\n");
                    break;
                }
                themSinhVien(sinhVien, p);
                break;
            case 2:
                printf("Danh sách sinh viên: \n");
                hienThi(sinhVien, p);
                break;
            case 3:
                luuDanhSach(sinhVien, p);
                printf("Thông tin sinh viên được lưu vào file danhsachsinhvien.txt.\n\n");
                break;
            case 4:
                docDanhSach();
                break;
            case 5:
                printf("Chương trình đã được thoát.");
                break;
            default:
                printf("Lua chọn của bạn không nằm trong menu !!!\n");
                printf("Vui lòng nhập lại lựa chọn !!!\n\n");
                break;
        }
        if (luachon == 5)
            break;
    }
    return 0;
}
