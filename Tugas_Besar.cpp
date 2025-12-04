#include <iostream>
#include "Tugas_Besar.h"

using namespace std;

void menu() {
    cout << "=== MENU PENGGUNA ===" << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "Siapa yang akan menggunakan aplikasi? ";
}

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

address findSong(List L, string id){
    address p = L.first;
    while(p != nullptr){
        if(p->info.id == id){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteAddress(List &L, address p){
    if(p == nullptr) return;
    
    if(p == L.first && p == L.last){
        L.first = nullptr;
        L.last = nullptr;
    }
    else if(p == L.first){
        L.first = p->next;
        L.first->prev = nullptr;
    }
    else if(p == L.last){
        L.last = p->prev;
        L.last->next = nullptr;
    }
    else{
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    delete p;
}

void showAllSongs(List L){
    if(isEmpty(L)){
        cout << "Library kosong.\n";
        return;
    }

    address p = L.first;
    cout << "\n=== DAFTAR SEMUA LAGU ===\n";
    while(p != nullptr){
        cout << "ID: " << p->info.id << endl;
        cout << "Judul: " << p->info.judul << endl;
        cout << "Penyanyi: " << p->info.penyanyi << endl;
        cout << "Durasi: " << p->info.durasi << endl;
        cout << "-------------------------\n";
        p = p->next;
    }
}

void updateSong(List &L){
    int pilihan;
    cout << "Cari judlu lagu yang ingin diupdate:\n";
    cout << "1. Judul Lagu\n";
    cout << "2. ID Lagu\n";
    cout << "Pilih: ";
    cin >> pilihan;

    address p = nullptr;

    if(pilihan == 1){
        string judul;
        cout << "Masukkan judul lagu: ";
        cin.ignore();
        getline(cin, judul);
        
        address temp = L.first;
        while(temp != nullptr && p == nullptr){
            if(temp->info.judul == judul){
                p = temp;
            }
            temp = temp->next;
        }
    } else if(pilihan == 2){
        string id;
        cout << "Masukkan ID lagu: ";
        cin >> id;
        p = findSong(L, id);
    } else {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    if(p == nullptr){
        cout << "Lagu tidak ditemukan.\n";
        return;
    }

    cout << "\nData lagu saat ini:\n";
    cout << "ID: " << p->info.id << endl;
    cout << "Judul: " << p->info.judul << endl;
    cout << "Penyanyi: " << p->info.penyanyi << endl;
    cout << "Durasi: " << p->info.durasi << endl;

    cout << "\nMasukkan data baru:\n";
    cout << "Judul: ";
    cin.ignore();
    getline(cin, p->info.judul);
    cout << "Penyanyi: ";
    getline(cin, p->info.penyanyi);
    cout << "Durasi: ";
    cin >> p->info.durasi;

    cout << "Data lagu berhasil diubah!\n";
}

void deleteSong(List &L){
    int pilihan;
    cout << "Cari lagu yang ingin dihapus berdasarkan:\n";
    cout << "1. Judul Lagu\n";
    cout << "2. ID Lagu\n";
    cout << "Pilih: ";
    cin >> pilihan;

    address p = nullptr;

    if(pilihan == 1){
        string judul;
        cout << "Masukkan judul lagu: ";
        cin.ignore();
        getline(cin, judul);
        
        address temp = L.first;
        while(temp != nullptr && p == nullptr){
            if(temp->info.judul == judul){
                p = temp;
            }
            temp = temp->next;
        }
    } else if(pilihan == 2){
        string id;
        cout << "Masukkan ID lagu: ";
        cin >> id;
        p = findSong(L, id);
    } else {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    if(p == nullptr){
        cout << "Lagu tidak ditemukan.\n";
        return;
    }

    cout << "Menghapus lagu: " << p->info.judul << " - " << p->info.penyanyi << endl;
    deleteAddress(L, p);
    cout << "Lagu berhasil dihapus dari library!\n";
}


void userSearchSong(List L){
    int pilihan;
    cout << "Cari berdasarkan:\n";
    cout << "1. Judul Lagu\n";
    cout << "2. ID Lagu\n";
    cout << "Pilih: ";
    cin >> pilihan;

    address p = L.first;
    bool found = false;

    if(pilihan == 1){
        string judul;
        cout << "Masukkan judul lagu: ";
        cin.ignore();
        getline(cin, judul);
        
        while(p != nullptr){
            if(p->info.judul.find(judul) != string::npos){
                cout << "\nDitemukan:\n";
                cout << "ID: " << p->info.id << endl;
                cout << "Judul: " << p->info.judul << endl;
                cout << "Penyanyi: " << p->info.penyanyi << endl;
                cout << "Durasi: " << p->info.durasi << endl;
                cout << "-------------------------\n";
                found = true;
            }
            p = p->next;
        }
        if(!found){
            cout << "Lagu tidak ditemukan.\n";
        }
    } else if(pilihan == 2){
        string id;
        cout << "Masukkan ID lagu: ";
        cin >> id;
        p = findSong(L, id);
        if(p != nullptr){
            cout << "\nDitemukan:\n";
            cout << "ID: " << p->info.id << endl;
            cout << "Judul: " << p->info.judul << endl;
            cout << "Penyanyi: " << p->info.penyanyi << endl;
            cout << "Durasi: " << p->info.durasi << endl;
        } else {
            cout << "Lagu tidak ditemukan.\n";
        }
    } else {
        cout << "Pilihan tidak valid.\n";
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
    int pilihan;
    cout << "Cari lagu yang ingin dihapus dari playlist berdasarkan:\n";
    cout << "1. Judul Lagu\n";
    cout << "2. ID Lagu\n";
    cout << "Pilih: ";
    cin >> pilihan;

    address p = nullptr;

    if(pilihan == 1){
        string judul;
        cout << "Masukkan judul lagu: ";
        cin.ignore();
        getline(cin, judul);
        
        address temp = playlist.first;
        while(temp != nullptr && p == nullptr){
            if(temp->info.judul == judul){
                p = temp;
            }
            temp = temp->next;
        }
    } else if(pilihan == 2){
        string id;
        cout << "Masukkan ID lagu: ";
        cin >> id;
        p = findSong(playlist, id);
    } else {
        cout << "Pilihan tidak valid.\n";
        return;
    }

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
