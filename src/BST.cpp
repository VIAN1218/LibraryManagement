#include "BST.h"
#include <iostream>

using namespace std;

BST::BST() {
    root = NULL;
}

NodeBST* BST::insertNode(NodeBST* root, Sach s) {
    if (root == NULL) {
        NodeBST* p = new NodeBST;

        p->data = s;
        p->left = NULL;
        p->right = NULL;

        return p;
    }

    if (s.tenSach < root->data.tenSach) {
        root->left = insertNode(root->left, s);
    }
    else if (s.tenSach > root->data.tenSach) {
        root->right = insertNode(root->right, s);
    }
    else {
        if (s.ISBN < root->data.ISBN) {
            root->left = insertNode(root->left, s);
        }
        else if (s.ISBN > root->data.ISBN) {
            root->right = insertNode(root->right, s);
        }
    }

    return root;
}

void BST::themSach(Sach s) {
    root = insertNode(root, s);
}

void BST::inorder(NodeBST* root) {
    if (root != NULL) {
        inorder(root->left);

        cout << "\nISBN: " << root->data.ISBN;
        cout << "\nTen sach: " << root->data.tenSach;
        cout << "\nTac gia: " << root->data.tacGia;
        cout << "\nThe loai: " << root->data.theLoai;
        cout << "\nNam xuat ban: " << root->data.namXuatBan;
        cout << "\nSo luong: " << root->data.soLuong;
        cout << "\n-------------------------\n";

        inorder(root->right);
    }
}

void BST::hienThiDanhMuc() {
    cout << "\n===== DANH MUC SACH THEO TEN =====\n";

    if (root == NULL) {
        cout << "Danh muc sach rong!\n";
        return;
    }

    inorder(root);
}

NodeBST* BST::findISBN(NodeBST* root, string ISBN) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data.ISBN == ISBN) {
        return root;
    }

    NodeBST* p = findISBN(root->left, ISBN);

    if (p != NULL) {
        return p;
    }

    return findISBN(root->right, ISBN);
}

NodeBST* BST::minNode(NodeBST* root) {
    NodeBST* p = root;

    while (p != NULL && p->left != NULL) {
        p = p->left;
    }

    return p;
}

NodeBST* BST::deleteNode(NodeBST* root, string tenSach, string ISBN) {
    if (root == NULL) {
        return NULL;
    }

    if (tenSach < root->data.tenSach) {
        root->left = deleteNode(root->left, tenSach, ISBN);
    }
    else if (tenSach > root->data.tenSach) {
        root->right = deleteNode(root->right, tenSach, ISBN);
    }
    else {
        if (ISBN < root->data.ISBN) {
            root->left = deleteNode(root->left, tenSach, ISBN);
        }
        else if (ISBN > root->data.ISBN) {
            root->right = deleteNode(root->right, tenSach, ISBN);
        }
        else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            if (root->left == NULL) {
                NodeBST* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                NodeBST* temp = root->left;
                delete root;
                return temp;
            }

            NodeBST* temp = minNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(
                root->right,
                temp->data.tenSach,
                temp->data.ISBN
            );
        }
    }

    return root;
}

void BST::xoaSach(string ISBN) {
    NodeBST* p = findISBN(root, ISBN);

    if (p == NULL) {
        return;
    }

    root = deleteNode(root, p->data.tenSach, ISBN);
}