#include <iostream>
#include <string>

#include "AVL.h"
#include "HashTable.h"
#include "BST.h"

using namespace std;


void menuSach(AVL& avl, BST& bst);
void menuDocGia(HashTable& ht);

int timTuanTu(string cmnd, int& soLan);
void themMang(DocGia dg);
void xoaMang(string cmnd);


DocGia dsDocGia[1000];
int soLuongDocGia = 0;

int timTuanTu(string cmnd, int& soLan) {
    soLan = 0;

    for (int i = 0; i < soLuongDocGia; i++) {
        soLan++;

        if (dsDocGia[i].cmnd == cmnd) {
            return i;
        }
    }

    return -1;
}


void themMang(DocGia dg) {
    if (soLuongDocGia < 1000) {
        dsDocGia[soLuongDocGia] = dg;
        soLuongDocGia++;
    }
    else {
        cout << "Mang doc gia da day!\n";
    }
}
void xoaMang(string cmnd) {
    int soLan;
    int viTri = timTuanTu(cmnd, soLan);

    if (viTri != -1) {
        for (int i = viTri; i < soLuongDocGia - 1; i++) {
            dsDocGia[i] = dsDocGia[i + 1];
        }

        soLuongDocGia--;
    }
}

void menuSach(AVL& avl, BST& bst) {
    int chon;

    do {
        cout << "\n===== QUAN LY SACH =====\n";
        cout << "1. Them sach\n";
        cout << "2. Tim sach\n";
        cout << "3. Xoa sach\n";
        cout << "4. Hien thi danh sach sach (AVL)\n";
        cout << "5. In danh muc sach theo ten (BST)\n";
        cout << "0. Quay lai\n";
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

            avl.themSach(s);
            bst.themSach(s);

            cout << "Da them sach vao AVL va BST!\n";

            break;
        }

        case 2: {
            string ISBN;

            cout << "Nhap ISBN can tim: ";
            cin >> ISBN;

            avl.timSach(ISBN);

            break;
        }

        case 3: {
            string ISBN;

            cout << "Nhap ISBN can xoa: ";
            cin >> ISBN;

            avl.xoaSach(ISBN);
            bst.xoaSach(ISBN);

            cout << "Da xoa sach khoi AVL va BST!\n";

            break;
        }

        case 4:
            avl.hienThi();
            break;

        case 5:
            bst.hienThiDanhMuc();
            break;

        case 0:
            cout << "Quay lai menu chinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);
}

void menuDocGia(HashTable& ht) {
    int chon;

    do {
        cout << "\n===== QUAN LY DOC GIA - HASH =====\n";
        cout << "1. Them doc gia\n";
        cout << "2. Tim doc gia\n";
        cout << "3. Xoa doc gia\n";
        cout << "4. Hien thi danh sach\n";
        cout << "5. So sanh Hash va tim tuan tu\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";

        cin >> chon;

        switch (chon) {

        case 1: {
            DocGia dg;

            cout << "Nhap CMND: ";
            cin >> dg.cmnd;

            cin.ignore();

            cout << "Nhap ho ten: ";
            getline(cin, dg.hoTen);

            cout << "Nhap so dien thoai: ";
            getline(cin, dg.soDienThoai);

            cout << "Nhap dia chi: ";
            getline(cin, dg.diaChi);

            int soLan;
            NodeDG* p = ht.timDocGia(dg.cmnd, soLan);

            if (p == NULL) {
                ht.themDocGia(dg);
                themMang(dg);
            }
            else {
                cout << "CMND da ton tai!\n";
            }

            break;
        }

        case 2: {
            string cmnd;
            int soLan = 0;

            cout << "Nhap CMND can tim: ";
            cin >> cmnd;

            NodeDG* p = ht.timDocGia(cmnd, soLan);

            if (p != NULL) {
                cout << "\nTim thay doc gia!\n";
                cout << "CMND: " << p->data.cmnd << endl;
                cout << "Ho ten: " << p->data.hoTen << endl;
                cout << "SDT: " << p->data.soDienThoai << endl;
                cout << "Dia chi: " << p->data.diaChi << endl;
            }
            else {
                cout << "Khong tim thay doc gia!\n";
            }

            cout << "So lan so sanh: " << soLan << endl;

            break;
        }

        case 3: {
            string cmnd;

            cout << "Nhap CMND can xoa: ";
            cin >> cmnd;

            int soLan;
            NodeDG* p = ht.timDocGia(cmnd, soLan);

            if (p != NULL) {
                ht.xoaDocGia(cmnd);
                xoaMang(cmnd);
            }
            else {
                cout << "Khong tim thay doc gia!\n";
            }

            break;
        }

        case 4:
            ht.hienThi();
            break;

        case 5: {
            string cmnd;

            cout << "Nhap CMND can tim: ";
            cin >> cmnd;

            int soLanHash = 0;
            int soLanTuanTu = 0;

            NodeDG* p = ht.timDocGia(cmnd, soLanHash);

            int viTri = timTuanTu(cmnd, soLanTuanTu);

            cout << "\n===== SO SANH HASH VA TIM TUAN TU =====\n";

            cout << "\nHash Table:\n";

            if (p != NULL) {
                cout << "Tim thay doc gia!\n";
            }
            else {
                cout << "Khong tim thay!\n";
            }

            cout << "So lan so sanh: "
                << soLanHash << endl;

            cout << "\nTim kiem tuan tu:\n";

            if (viTri != -1) {
                cout << "Tim thay doc gia!\n";
            }
            else {
                cout << "Khong tim thay!\n";
            }

            cout << "So lan so sanh: "
                << soLanTuanTu << endl;

            break;
        }

        case 0:
            cout << "Quay lai menu chinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);
}

int main() {
    AVL avl;
    BST bst;
    HashTable ht;

    int chon;

    do {
        cout << "\n================================\n";
        cout << "    QUAN LY THU VIEN C++\n";
        cout << "================================\n";
        cout << "1. Quan ly sach (AVL + BST)\n";
        cout << "2. Quan ly doc gia (Hash Table)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Nhap lua chon: ";

        cin >> chon;

        switch (chon) {

        case 1:
            menuSach(avl, bst);
            break;

        case 2:
            menuDocGia(ht);
            break;

        case 0:
            cout << "Thoat chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;
}