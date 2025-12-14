#include <iostream>
#include "Tugas Besar.h"
using namespace std;

int main() {
    List library;      // Library untuk semua lagu
    List playlist;     // Playlist user
    List favorite;     // Playlist favorit user
    List queue;

    address currentSong = nullptr;  // Untuk menyimpan lagu
    infotype lagu;
    string pilihan;
    string username;

    createList(library);
    createList(playlist);
    createList(favorite);
    createList(queue);

    bool running = true;

    initDummySongs(library);

    while (running) {
        menu();
        cin >> pilihan;
        cout << endl;

        if (pilihan == "Admin" || pilihan == "admin" || pilihan == "1") {
            int pilihanAdmin = -1;
            createList(queue);
            if (loginAdmin()) {
                cout << "Login admin berhasil!\n" << endl;
            }
            while (pilihanAdmin != 0){
                cout << "\n========== MENU ADMIN ==========" << endl;
                cout << "1. Menambahkan lagu ke library" << endl;
                cout << "2. Melihat semua lagu di library" << endl;
                cout << "3. Mengubah data lagu di library" << endl;
                cout << "4. Menghapus data lagu di library" << endl;
                cout << "0. Kembali ke menu utama" << endl;
                cout << "Pilih: ";
                cin >> pilihanAdmin;

                cout << endl;
                if (pilihanAdmin == 1) {
                    addNewSong(library, lagu);
                }
                else if (pilihanAdmin == 2) {
                    showAllSongs(library);
                }
                else if (pilihanAdmin == 3) {
                    updateSong(library);
                }
                else if (pilihanAdmin == 4) {
                    deleteSong(library);
                }
                else if (pilihanAdmin == 0) {
                    cout << "Logout admin...\n";
                }
                else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        }

        else if (pilihan == "User" || pilihan == "user" || pilihan == "2") {
            int pilihanUser = -1;
            address song = nullptr;
            List daftarlagu;

            if (loginUser(username)) {
                cout << "Login user berhasil!\n";
            }
            while(pilihanUser != 0){
                cout << "\n========= MENU USER =========" << endl;
                cout << "1. Show lagu" << endl;
                cout << "2. Mencari lagu" << endl;
                cout << "3. Play lagu dari playlist" << endl;
                cout << "4. Stop lagu" << endl;
                cout << "5. Memutar lagu selanjutnya" << endl;
                cout << "6. Memutar lagu sebelumnya" << endl;
                cout << "7. Menambahkan lagu ke playlist" << endl;
                cout << "8. Menghapus lagu dari playlist" << endl;
                cout << "9. Melihat isi playlist" << endl;
                cout << "10. Tambah ke favorit" << endl;
                cout << "11. Lihat favorit" << endl;
                cout << "12. Tambah ke antrian" << endl;
                cout << "13. Putar antrian" << endl;
                cout << "0. Kembali ke menu utama" << endl;
                cout << "Pilih: ";
                cin >> pilihanUser;

                cout << endl;

                if (pilihanUser == 1) {
                    showAllSongs(library);
                }
                else if (pilihanUser == 2) {
                    userSearchSong(library);
                }
                else if (pilihanUser == 3) {
                    if (!isEmpty(playlist)) {
                        currentSong = playlist.first;
                        playSong(currentSong);
                    } else {
                        cout << "Playlist kosong.\n";
                    }
                }
                else if (pilihanUser == 4) {
                    stopSong(currentSong);
                }
                else if (pilihanUser == 5) {
                    nextSong(currentSong);
                }
                else if (pilihanUser == 6) {
                    prevSong(currentSong);
                }
                else if (pilihanUser == 7) {
                    string id;
                    cout << "Masukkan ID lagu untuk ditambahkan ke playlist: ";
                    cin >> id;

                    address p = searchById(library, id);
                    if (p != nullptr) {
                        addToPlaylist(playlist, p);
                    } else {
                        cout << "Lagu tidak ditemukan!\n";
                    }
                }
                else if (pilihanUser == 8) {
                    removeFromPlaylist(playlist);
                }
                else if (pilihanUser == 9) {
                    showPlaylist(playlist);
                }
                else if (pilihanUser == 10) {
                    likedSongs(library, favorite);
                }
                else if (pilihanUser == 11) {
                    if (!isEmpty(favorite)) {
                        showLikedSongs(favorite);
                    } else {
                        cout << "Playlist Favorite Song kosong.\n";
                    }
                }
                else if (pilihanUser == 12) {
                    string id;
                    cout << "ID lagu: ";
                    cin >> id;
                    address p = searchById(library, id);
                    if (p != nullptr) {
                        enqueueSong(queue, p);
                    } else {
                        cout << "Lagu tidak ditemukan.\n";
                    }
                }
                else if (pilihanUser == 13) {
                    if (!isEmpty(playlist)) {
                        playQueue(queue, currentSong);
                    } else {
                        cout << "Antrian kosong.\n";
                    }
                }
                else if (pilihanUser == 0) {
                    cout << "Logout user berhasil.\n";
                }
                else {
                    cout << "Pilihan tidak valid!\n";
                }
                if (pilihanUser != 0) {
                    cout << "\nTekan ENTER untuk kembali ke menu user...";
                    cin.get();
                    cin.get();
                }
            }
        }
        else if (pilihan == "Keluar" || pilihan == "keluar" || pilihan == "3") {
            cout << "\n====================================\n";
            cout << "  Terima kasih telah menggunakan\n";
            cout << "      Aplikasi Music Player \n";
            cout << "  Sampai jumpa di lain waktu!\n";
            cout << "====================================\n";
        running = false; // ❗ STOP PROGRAM}
        }
    }
    return 0;
}
