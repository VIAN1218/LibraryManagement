#ifndef BST_H
#define BST_H

#include "AVL.h"

struct NodeBST {
    Sach data;
    NodeBST* left;
    NodeBST* right;
};

class BST {
private:
    NodeBST* root;

    NodeBST* insertNode(NodeBST* root, Sach s);
    void inorder(NodeBST* root);
    NodeBST* findISBN(NodeBST* root, string ISBN);
    NodeBST* deleteNode(NodeBST* root, string tenSach, string ISBN);
    NodeBST* minNode(NodeBST* root);

public:
    BST();

    void themSach(Sach s);
    void xoaSach(string ISBN);
    void hienThiDanhMuc();
};

#endif