#include "TUBES_STD.h"

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmpty(List L) {
    return (L.first == nullptr && L.last == nullptr);
}

address createElement(infotype x) {
    address p = new elmlist;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void insertLast(List &L, address p) {
    if (isEmpty(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void deleteAddress(List &L, address p) {
    if (p != nullptr) {
        if (p == L.first && p == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        }
        else if (p == L.first) {
            L.first = p->next;
            L.first->prev = nullptr;
        }
        else if (p == L.last) {
            L.last = p->prev;
            L.last->next = nullptr;
        }
        else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        delete p;
    }
}

address searchById(List L, string id) {
    address p = L.first;
    address hasil = nullptr;

    while (p != nullptr && hasil == nullptr) {
        if (p->info.id == id) {
            hasil = p;
        }
        p = p->next;
    }

    return hasil;
}

address searchByTitle(List L, string judul) {
    address p = L.first;
    address hasil = nullptr;

    while (p != nullptr && hasil == nullptr) {
        if (p->info.judul == judul) {
            hasil = p;
        }
        p = p->next;
    }

    return hasil;
}


void showSong(address p) {
    if (p != nullptr) {
        cout << "ID       : " << p->info.id << endl;
        cout << "Judul    : " << p->info.judul << endl;
        cout << "Penyanyi : " << p->info.penyanyi << endl;
        cout << "Durasi   : " << p->info.durasi << endl;
    } else {
        cout << "Tidak ada lagu.\n";
    }
}

void showAllSongs(List L) {
    address p = L.first;

    if (p == nullptr) {
        cout << "List lagu kosong.\n";
    } else {
        while (p != nullptr) {
            showSong(p);
            cout << "----------------------\n";
            p = p->next;
        }
    }
}


void playSong(address &p) {
    if (p != nullptr) {
        cout << "Memutar lagu:\n";
        cout << p->info.judul << " - " << p->info.penyanyi << endl;
    } else {
        cout << "Belum ada lagu yang dipilih.\n";
    }
}

void stopSong(address &p) {
    if (p != nullptr) {
        cout << "Lagu dihentikan: " << p->info.judul << endl;
        p = nullptr;
    } else {
        cout << "Tidak ada lagu yang sedang diputar.\n";
    }
}

void nextSong(address &p) {
    if (p != nullptr) {
        if (p->next != nullptr) {
            p = p->next;
            playSong(p);
        } else {
            cout << "Sudah di lagu terakhir.\n";
        }
    } else {
        cout << "Belum ada lagu yang dipilih.\n";
    }
}

void prevSong(address &p) {
    if (p != nullptr) {
        if (p->prev != nullptr) {
            p = p->prev;
            playSong(p);
        } else {
            cout << "Sudah di lagu pertama.\n";
        }
    } else {
        cout << "Belum ada lagu yang dipilih.\n";
    }
}

void enqueueSong(List &queue, address song) {
    address newNode = createElement(song->info);
    insertLast(queue, newNode);
    cout << "Lagu masuk antrian.\n";
}

void playQueue(List &queue, address &currentSong) {
    if (isEmpty(queue)) {
        cout << "Antrian kosong.\n";
    } else {
        address p = queue.first;
        currentSong = p;
        playSong(currentSong);
        deleteAddress(queue, p);
    }
}


