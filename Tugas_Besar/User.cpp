#include "Tugas Besar.h"

bool logInUser(string &username) {
    cout << "Masukkan username: ";
    getline(cin, username);
    cout << "Log in berhasil sebagai " << username << endl;
    return true;
}

void menuUser(List &library, List &favorite, List &queue) {
    int pilih = -1;
    address currentSong = nullptr;
    List *activeList = &library;

    List userPlaylists[100];
    string namaPlaylist[100];
    int jumlahPlaylist = 0;

    for (int i = 0; i < 100; i++) {
        createList(userPlaylists[i]);
    }

    while (pilih != 0) {
        cout << "\n====== MENU USER ======\n";
        cout << "Lagu aktif: ";
        if (currentSong != nullptr)
            cout << currentSong->info.judul << endl;
        else
            cout << "(belum dipilih)\n";

        cout << "1. Lihat semua lagu\n";
        cout << "2. Pilih lagu\n";
        cout << "3. Putar lagu\n";
        cout << "4. Lagu selanjutnya\n";
        cout << "5. Lagu sebelumnya\n";
        cout << "6. Menu Playlist\n";
        cout << "7. Tambah ke antrian\n";
        cout << "8. Putar antrian\n";
        cout << "0. Log Out\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            showAllSongsLibrary(library);
        } else if (pilih == 2) {
            currentSong = searchSong(library);
            activeList = &library;
        } else if (pilih == 3) {
            playSong(currentSong);
        } else if (pilih == 4) {
            nextSong(currentSong, *activeList);
        } else if (pilih == 5) {
            prevSong(currentSong, *activeList);
        } else if (pilih == 6) {
            menuPlaylistUser(library, favorite, userPlaylists, namaPlaylist, jumlahPlaylist, currentSong, activeList);
        } else if (pilih == 7) {
            if (currentSong != nullptr) {
                enqueueSong(queue, currentSong);
            } else {
                cout << "Pilih lagu terlebih dahulu.\n";
            }
        } else if (pilih == 8) {
            playQueue(queue, currentSong);
        }
    }
}
