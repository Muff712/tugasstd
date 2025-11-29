#include <iostream>
#include "Tugas_Besar.h"

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


void userSearchSong(List L){
    string id;
    cout << "Masukkan ID lagu: ";
    cin >> id;

    address p = findSong(L, id);
    if(p == nullptr){
        cout << "Lagu tidak ditemukan.\n";
    }
    else{
        cout << "Ditemukan: " << p->info.judul << " - " << p->info.penyanyi << endl;
    }
}

void playSong(address &p){
    if(p == nullptr){
        cout << "Tidak ada lagu dipilih.\n";
        return;
    }
    cout << "Memutar: " << p->info.judul << endl;
}
void stopSong(address &p){
     if(p == nullptr){
        cout << "Tidak ada lagu yang sedang diputar.\n";
        return;
    }
    cout << "Lagu dihentikan.\n";
}

void nextSong(address &p){
    if(p == nullptr){
        cout << "Tidak ada lagu yang sedang diputar.\n";
        return;
    }

    if(p->next != nullptr){
        p = p->next;
        playSong(p);
    } else {
        cout << "Ini adalah lagu terakhir.\n";
    }
}

void prevSong(address &p){
    if(p == nullptr){
        cout << "Tidak ada lagu yang sedang diputar.\n";
        return;
    }

    if(p->prev != nullptr){
        p = p->prev;
        playSong(p);
    } else {
        cout << "Ini lagu pertama.\n";
    }
}

void addToPlaylist(List &playlist, address song){
    insertLast(playlist, createElement(song->info));
    cout << "Lagu ditambahkan ke playlist!\n";
}
void removeFromPlaylist(List &playlist){
    string id;
    cout << "Masukkan ID lagu yang ingin dihapus dari playlist: ";
    cin >> id;

    address p = findSong(playlist, id);
    if(p == nullptr){
        cout << "Lagu tidak ditemukan di playlist.\n";
        return;
    }

    deleteAddress(playlist, p);
    cout << "Dihapus dari playlist.\n";
}

void showPlaylist(List playlist){
    if(isEmpty(playlist)){
        cout << "Playlist kosong.\n";
        return;
    }

    address p = playlist.first;
    while(p != nullptr){
        cout << p->info.id << " | "
             << p->info.judul << " - "
             << p->info.penyanyi << endl;
        p = p->next;
    }
}
