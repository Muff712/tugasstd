#include <iostream>
#include "Tugas Besar.h"

using namespace std;

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmpty(List L) {
    if (L.first == nullptr && L.last == nullptr) {
        return true;
    } else {
        return false;
    }
}

address createElement(infotype x) {
    address p = new elmlist;

    p -> info = x;
    p -> next = nullptr;
    p -> prev = nullptr;

    return p;
}

void insertLast(List &L, address p) {
    if (isEmpty(L)) {
        L.first = p;
        L.last = p;
    } else {
        p -> prev = L.last;
        L.last -> next = p;
        L.last = p;
    }
}

void addNewSong(List &L, infotype x) {
    cout << "Masukkan ID Lagu: ";
    cin >> x.id;

    while (x.id != "Selesai" && x.id != "selesai") {
        cout << "Masukkan Judul Lagu: ";
        cin >> x.judul;

        cout << "Masukkan Penyanyi Lagu: ";
        cin >> x.penyanyi;

        cout << "Masukkan Durasi Lagu: ";
        cin >> x.durasi;

        address p = createElement(x);
        insertLast(L, p);

        cout << "Masukkan ID Lagu: ";
        cin >> x.id;
    }
    cout << "Lagu telah ditambahkan!";
}

