#include "AVL.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    AVL dsSach;
    int chon;
    string ISBN;

    do {
        cout << "\n===== QUAN LY SACH =====\n";
        cout << "1. Them sach\n";
        cout << "2. Tim sach\n";
        cout << "3. Hien thi danh sach\n";
        cout << "4. Xoa sach\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
        case 1: {
            Sach s;

            cout << "Nhap ISBN: ";
            cin >> s.ISBN;

            cin.ignore();

            cout << "Nhap ten sach: ";
            getline(cin, s.tenSach);

            cout << "Nhap tac gia: ";
            getline(cin, s.tacGia);

            cout << "Nhap the loai: ";
            getline(cin, s.theLoai);

            cout << "Nhap nam xuat ban: ";
            cin >> s.namXuatBan;

            cout << "Nhap so luong: ";
            cin >> s.soLuong;

            dsSach.themSach(s);

            break;
        }

        case 2: {
            cout << "Nhap ISBN can tim: ";
            cin >> ISBN;

            dsSach.timSach(ISBN);

            break;
        }

        case 3: {
            dsSach.hienThi();

            break;
        }

        case 4: {
            cout << "Nhap ISBN can xoa: ";
            cin >> ISBN;

            dsSach.xoaSach(ISBN);

            break;
        }

        case 0:
            cout << "Thoat chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;
}
