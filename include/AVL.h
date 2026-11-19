#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>

using namespace std;

// Cau truc sach
struct Sach {
    string ISBN;
    string tenSach;
    string tacGia;
    string theLoai;
    int namXuatBan;
    int soLuong;
};

// Cau truc node AVL
struct NodeAVL {
    Sach data;
    NodeAVL* left;
    NodeAVL* right;
    int height;

    NodeAVL(Sach s) {
        data = s;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Lop AVL
class AVL {
private:
    NodeAVL* root;

    int getHeight(NodeAVL* p);
    int getBalance(NodeAVL* p);

    NodeAVL* rotateRight(NodeAVL* y);
    NodeAVL* rotateLeft(NodeAVL* x);

    NodeAVL* insertNode(NodeAVL* node, Sach s);
    NodeAVL* searchNode(NodeAVL* node, string ISBN);

    NodeAVL* minValueNode(NodeAVL* node);
    NodeAVL* deleteNode(NodeAVL* node, string ISBN);

    void displayNode(NodeAVL* node);

public:
    AVL();

    void themSach(Sach s);
    void timSach(string ISBN);
    void xoaSach(string ISBN);
    void hienThi();
};

#endif