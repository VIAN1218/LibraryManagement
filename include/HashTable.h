#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "DocGia.h"

const int TABLE_SIZE = 10;

struct NodeDG {
    DocGia data;
    NodeDG* next;
};

class HashTable {
private:
    NodeDG* table[TABLE_SIZE];

    int hashFunction(string cmnd);

public:
    HashTable();

    void themDocGia(DocGia dg);
    NodeDG* timDocGia(string cmnd, int& soLan);
    void xoaDocGia(string cmnd);
    void hienThi();
};

#endif