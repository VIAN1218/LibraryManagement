#include "AVL.h"
#include <algorithm>

using namespace std;

// Khoi tao cay
AVL::AVL() {
    root = nullptr;
}

// Lay chieu cao
int AVL::getHeight(NodeAVL* p) {
    if (p == nullptr)
        return 0;

    return p->height;
}

// Tinh he so can bang
int AVL::getBalance(NodeAVL* p) {
    if (p == nullptr)
        return 0;

    return getHeight(p->left) - getHeight(p->right);
}

// Xoay phai
NodeAVL* AVL::rotateRight(NodeAVL* y) {
    NodeAVL* x = y->left;
    NodeAVL* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
        getHeight(x->right));

    return x;
}

// Xoay trai
NodeAVL* AVL::rotateLeft(NodeAVL* x) {
    NodeAVL* y = x->right;
    NodeAVL* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
        getHeight(y->right));

    return y;
}

// Them node vao cay
NodeAVL* AVL::insertNode(NodeAVL* node, Sach s) {
    if (node == nullptr)
        return new NodeAVL(s);

    if (s.ISBN < node->data.ISBN)
        node->left = insertNode(node->left, s);

    else if (s.ISBN > node->data.ISBN)
        node->right = insertNode(node->right, s);

    else {
        cout << "ISBN da ton tai!\n";
        return node;
    }

    // Cap nhat chieu cao
    node->height = 1 + max(getHeight(node->left),
        getHeight(node->right));

    // Tinh he so can bang
    int balance = getBalance(node);

    // LL
    if (balance > 1 &&
        s.ISBN < node->left->data.ISBN)
        return rotateRight(node);

    // RR
    if (balance < -1 &&
        s.ISBN > node->right->data.ISBN)
        return rotateLeft(node);

    // LR
    if (balance > 1 &&
        s.ISBN > node->left->data.ISBN) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL
    if (balance < -1 &&
        s.ISBN < node->right->data.ISBN) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Tim node
NodeAVL* AVL::searchNode(NodeAVL* node, string ISBN) {
    if (node == nullptr ||
        node->data.ISBN == ISBN)
        return node;

    if (ISBN < node->data.ISBN)
        return searchNode(node->left, ISBN);

    return searchNode(node->right, ISBN);
}

// Tim node nho nhat
NodeAVL* AVL::minValueNode(NodeAVL* node) {
    NodeAVL* p = node;

    while (p != nullptr && p->left != nullptr)
        p = p->left;

    return p;
}

// Xoa node
NodeAVL* AVL::deleteNode(NodeAVL* node, string ISBN) {
    if (node == nullptr)
        return node;

    // Tim node can xoa
    if (ISBN < node->data.ISBN)
        node->left = deleteNode(node->left, ISBN);

    else if (ISBN > node->data.ISBN)
        node->right = deleteNode(node->right, ISBN);

    else {
        // Node khong co con
        if (node->left == nullptr &&
            node->right == nullptr) {
            delete node;
            return nullptr;
        }

        // Node co 1 con phai
        else if (node->left == nullptr) {
            NodeAVL* temp = node->right;
            delete node;
            return temp;
        }

        // Node co 1 con trai
        else if (node->right == nullptr) {
            NodeAVL* temp = node->left;
            delete node;
            return temp;
        }

        // Node co 2 con
        else {
            NodeAVL* temp = minValueNode(node->right);

            node->data = temp->data;

            node->right = deleteNode(node->right,
                temp->data.ISBN);
        }
    }

    // Cap nhat chieu cao
    node->height = 1 + max(getHeight(node->left),
        getHeight(node->right));

    // Tinh he so can bang
    int balance = getBalance(node);

    // LL
    if (balance > 1 &&
        getBalance(node->left) >= 0)
        return rotateRight(node);

    // LR
    if (balance > 1 &&
        getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RR
    if (balance < -1 &&
        getBalance(node->right) <= 0)
        return rotateLeft(node);

    // RL
    if (balance < -1 &&
        getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Hien thi node
void AVL::displayNode(NodeAVL* node) {
    if (node == nullptr)
        return;

    displayNode(node->left);

    cout << node->data.ISBN << " | "
        << node->data.tenSach << " | "
        << node->data.tacGia << " | "
        << node->data.theLoai << " | "
        << node->data.namXuatBan << " | "
        << node->data.soLuong << endl;

    displayNode(node->right);
}

// Them sach
void AVL::themSach(Sach s) {
    root = insertNode(root, s);
}

// Tim sach
void AVL::timSach(string ISBN) {
    NodeAVL* p = searchNode(root, ISBN);

    if (p == nullptr) {
        cout << "Khong tim thay sach!\n";
    }
    else {
        cout << "\n===== THONG TIN SACH =====\n";
        cout << "ISBN: " << p->data.ISBN << endl;
        cout << "Ten sach: " << p->data.tenSach << endl;
        cout << "Tac gia: " << p->data.tacGia << endl;
        cout << "The loai: " << p->data.theLoai << endl;
        cout << "Nam XB: " << p->data.namXuatBan << endl;
        cout << "So luong: " << p->data.soLuong << endl;
    }
}

// Xoa sach
void AVL::xoaSach(string ISBN) {
    NodeAVL* p = searchNode(root, ISBN);

    if (p == nullptr) {
        cout << "Khong tim thay sach!\n";
    }
    else {
        root = deleteNode(root, ISBN);
        cout << "Xoa sach thanh cong!\n";
    }
}

// Hien thi danh sach
void AVL::hienThi() {
    cout << "\n===== DANH SACH SACH =====\n";

    cout << "ISBN | Ten sach | Tac gia | The loai"
        << " | Nam XB | So luong\n";

    displayNode(root);
}
