#include "TUBES_STD.h"

bool loginUser(string &username) {
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Login berhasil sebagai " << username << endl;
    return true;
}

void menuUser(List &library, List &favorite, List &queue) {
    int pilih = -1;
    address currentSong = nullptr;

    while (pilih != 0) {
        cout << "\n=== MENU USER ===\n";
        cout << "Lagu aktif: ";
        if (currentSong != nullptr) {
            cout << currentSong->info.judul << endl;
        } else {
            cout << "(belum dipilih)\n";
        }

        cout << "1. Lihat semua lagu\n";
        cout << "2. Pilih lagu (judul)\n";
        cout << "3. Play lagu\n";
        cout << "4. Next\n";
        cout << "5. Prev\n";
        cout << "6. Tambah ke favorit\n";
        cout << "7. Lihat favorit\n";
        cout << "8. Tambah ke antrian\n";
        cout << "9. Putar antrian\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            showAllSongs(library);
        }

        else if (pilih == 2) {
            string judul;
            cout << "Masukkan judul lagu: ";
            cin >> judul;

            currentSong = searchByTitle(library, judul);

            if (currentSong != nullptr) {
                cout << "Lagu ditemukan dan dipilih:\n";
                showSong(currentSong);
            } else {
                cout << "Lagu tidak ditemukan.\n";
            }
        }

        else if (pilih == 3) {
            playSong(currentSong);
        }

        else if (pilih == 4) {
            nextSong(currentSong);
        }

        else if (pilih == 5) {
            prevSong(currentSong);
        }

        else if (pilih == 6) {
            if (currentSong != nullptr) {
                insertLast(favorite, createElement(currentSong->info));
                cout << "Lagu ditambahkan ke favorit.\n";
            } else {
                cout << "Pilih lagu terlebih dahulu.\n";
            }
        }

        else if (pilih == 7) {
            showAllSongs(favorite);
        }

        else if (pilih == 8) {
            if (currentSong != nullptr) {
                enqueueSong(queue, currentSong);
                cout << "Lagu ditambahkan ke antrian.\n";
            } else {
                cout << "Pilih lagu terlebih dahulu.\n";
            }
        }

        else if (pilih == 9) {
            playQueue(queue, currentSong);
        }
    }
}
