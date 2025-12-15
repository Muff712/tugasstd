#include "Tugas Besar.h"
#include <iostream>
using namespace std;

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

List searchBySinger(List L, string penyanyi) {
    List lagupenyanyi;

    createList(lagupenyanyi);

    address p = L.first;
    while (p!= nullptr) {
        if (p->info.penyanyi == penyanyi) {
            address newNode = createElement(p->info);
            insertLast(lagupenyanyi, newNode);
        }
        p = p->next;
    }
    return lagupenyanyi;
}

address searchSong(List L) {
    address currentSong = nullptr;
    int berdasarkanapa;

    cout << "1. ID" << endl;
    cout << "2. Judul" << endl;
    cout << "3. Penyanyi" << endl;
    cout << "Pilih: ";
    cin >> berdasarkanapa;
    cin.ignore();

    if (berdasarkanapa == 1) {
        string id;

        cout << "Masukkan ID lagu: ";
        getline(cin, id);
        currentSong = searchById(L, id);
    } else if (berdasarkanapa == 2) {
        string judul;

        cout << "Masukkan judul lagu: ";
        getline(cin, judul);
        currentSong = searchByTitle(L, judul);
    } else if (berdasarkanapa == 3) {
        string penyanyi;
        List lagunya;

        cout << "Masukkan penyanyi lagu: ";
        getline(cin, penyanyi);
        lagunya = searchBySinger(L, penyanyi);

        if (isEmpty(lagunya)) {
            cout << "Tidak ada lagu dari penyanyi tersebut.\n";
            return nullptr;
        } else {
            showAllSongsLibrary(lagunya);

            string judul;
            cout << "Masukkan judul lagu: ";
            getline(cin, judul);
            currentSong = searchByTitle(lagunya, judul);
        }
    }
    if (currentSong != nullptr) {
        cout << "Lagu berhasil dipilih.\n";
        showSong(currentSong);
    } else {
        cout << "Lagu tidak ditemukan.\n";
    }
    return currentSong;
}

void showSong(address p) {
    if (p != nullptr) {
        cout << "ID       : " << p->info.id << endl;
        cout << "Judul    : " << p->info.judul << endl;
        cout << "Penyanyi : " << p->info.penyanyi << endl;
        cout << "Durasi   : " << p->info.durasi << endl;
    } else {
        cout << "Lagu tidak ditemukan.\n";
    }
}

void showAllSongsLibrary(List L) {
    address p = L.first;

    if (p == nullptr) {
        cout << "Library kosong.\n";
    } else {
        while (p != nullptr) {
            showSong(p);
            cout << "-------------------------------------\n";
            p = p->next;
        }
    }
}

void showAllSongsPlaylist(List L) {
    address p = L.first;

    if (p == nullptr) {
        cout << "Playlist kosong.\n";
    } else {
        while (p != nullptr) {
            showSong(p);
            cout << "-------------------------------------\n";
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
        cout << "Lagu dihentikan: " << p->info.judul << " - " << p->info.penyanyi << endl;
        p = nullptr;
    } else {
        cout << "Tidak ada lagu yang sedang diputar.\n";
    }
}

void nextSong(address &p, List L) {
    if (p != nullptr) {
        if (p->next != nullptr) {
            p = p->next;
        } else {
            p = L.first;
        }
        playSong(p);
    } else {
        cout << "Belum ada lagu yang dipilih.\n";
    }
}

void prevSong(address &p, List L) {
    if (p != nullptr) {
        if (p->prev != nullptr) {
            p = p->prev;
            playSong(p);
        } else {
            p = L.last;
        }
        playSong(p);
    } else {
        cout << "Belum ada lagu yang dipilih.\n";
    }
}

void addSongToUserPlaylist(List &playlistUser, address song) {
    if (song != nullptr) {
        insertLast(playlistUser, createElement(song->info));
        cout << "Lagu ditambahkan ke playlist.\n";
    } else {
        cout << "Belum ada lagu yang dipilih.\n";
    }
}

void menuPlaylistUser(List &library, List &favorite, List userPlaylists[], string namaPlaylist[], int &jumlahPlaylist, address &currentSong, List *&activeList) {
    int pilih = -1;

    while (pilih != 0) {
        cout << "\n====== MENU PLAYLIST ======\n";
        cout << "1. Playlist Favorit\n";

        for (int i = 0; i < jumlahPlaylist; i++) {
            cout << i + 2 << ". " << namaPlaylist[i] << endl;
        }

        cout << jumlahPlaylist + 2 << ". Buat playlist baru\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 0) {
            return;
        } else if (pilih == 1) {
            int aksi = -1;
            while (aksi != 0) {
                cout << "\n--- Playlist Favorit ---\n";
                cout << "1. Lihat lagu\n";
                cout << "2. Tambah lagu\n";
                cout << "3. Putar lagu\n";
                cout << "0. Kembali\n";
                cout << "Pilih: ";
                cin >> aksi;
                cin.ignore();

                if (aksi == 1) {
                    showAllSongsPlaylist(favorite);
                } else if (aksi == 2) {
                    address lagu = searchSong(library);
                    if (lagu != nullptr) {
                        insertLast(favorite, createElement(lagu->info));
                        cout << "Lagu ditambahkan ke favorit.\n";
                    }
                } else if (aksi == 3) {
                    string judul;

                    cout << "Masukkan judul lagu: ";
                    getline(cin, judul);
                    address p = searchByTitle(favorite, judul);

                    if (p !=nullptr) {
                        currentSong = p;
                        activeList = &favorite;
                        playSong(currentSong);
                    } else {
                        cout << "Lagu tidak ditemukan di dalam playlist.\n";
                    }
                }
            }
        } else if (pilih == jumlahPlaylist + 2) {
            if (jumlahPlaylist >= 100) {
                cout << "Jumlah playlist sudah mencapai batas maksimum.\n";
            } else {
                cout << "Masukkan nama playlist: ";
                getline(cin, namaPlaylist[jumlahPlaylist]);
                createList(userPlaylists[jumlahPlaylist]);
                jumlahPlaylist++;
                cout << "Playlist berhasil dibuat.\n";
            }
        } else {
            int idx = pilih - 2;

            if (idx >= 0 && idx < jumlahPlaylist) {
                int aksi = -1;

                while (aksi != 0) {
                    cout << "\n--- Playlist: " << namaPlaylist[idx] << " ---\n";
                    cout << "1. Lihat lagu\n";
                    cout << "2. Tambah lagu\n";
                    cout << "3. Putar lagu\n";
                    cout << "0. Kembali\n";
                    cout << "Pilih: ";
                    cin >> aksi;
                    cin.ignore();

                    if (aksi == 1) {
                        showAllSongsPlaylist(userPlaylists[idx]);
                    } else if (aksi == 2) {
                        address lagu = searchSong(library);
                        addSongToUserPlaylist(userPlaylists[idx], lagu);
                    } else if (aksi == 3) {
                        string judul;

                        cout << "Masukkan judul lagu: ";
                        getline(cin, judul);
                        address p = searchByTitle(userPlaylists[idx], judul);

                        if (p != nullptr) {
                            currentSong = p;
                            activeList = &userPlaylists[idx];
                            playSong(currentSong);
                        } else {
                            cout << "Lagu tidak ditemukan di dalam playlist.\n";
                        }
                    }
                }
            }
        }
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
