#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

int HashTable::hashFunction(string cmnd) {
    int hash = 0;

    for (int i = 0; i < cmnd.length(); i++) {
        hash = (hash * 10 + (cmnd[i] - '0')) % TABLE_SIZE;
    }

    return hash;
}

NodeDG* HashTable::timDocGia(string cmnd, int& soLan) {
    int index = hashFunction(cmnd);

    NodeDG* p = table[index];

    soLan = 0;

    while (p != NULL) {
        soLan++;

        if (p->data.cmnd == cmnd) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

void HashTable::themDocGia(DocGia dg) {
    int soLan;

    if (timDocGia(dg.cmnd, soLan) != NULL) {
        cout << "CMND da ton tai!\n";
        return;
    }

    int index = hashFunction(dg.cmnd);

    NodeDG* newNode = new NodeDG;

    newNode->data = dg;
    newNode->next = table[index];

    table[index] = newNode;

    cout << "Them doc gia thanh cong!\n";
}

void HashTable::xoaDocGia(string cmnd) {
    int index = hashFunction(cmnd);

    NodeDG* p = table[index];
    NodeDG* prev = NULL;

    while (p != NULL) {
        if (p->data.cmnd == cmnd) {
            if (prev == NULL) {
                table[index] = p->next;
            }
            else {
                prev->next = p->next;
            }

            delete p;

            cout << "Xoa doc gia thanh cong!\n";
            return;
        }

        prev = p;
        p = p->next;
    }

    cout << "Khong tim thay doc gia!\n";
}

void HashTable::hienThi() {
    cout << "\n===== DANH SACH DOC GIA =====\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        NodeDG* p = table[i];

        if (p != NULL) {
            cout << "\nHash [" << i << "]\n";

            while (p != NULL) {
                cout << "CMND: " << p->data.cmnd << endl;
                cout << "Ho ten: " << p->data.hoTen << endl;
                cout << "SDT: " << p->data.soDienThoai << endl;
                cout << "Dia chi: " << p->data.diaChi << endl;
                cout << "--------------------\n";

                p = p->next;
            }
        }
    }
}