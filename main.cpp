#include <iostream>
#include "Tugas Besar.h"

using namespace std;


int main(){
    List library;      // Library untuk semua lagu
    List playlist;     // Playlist user
    List favorite;     // Playlist favorit user
    address currentSong = nullptr;  // Untuk menyimpan lagu
    infotype lagu;
    string pilihan;

    createList(library);
    createList(playlist);

    while(true){
        menu();
        cin >> pilihan;

        cout << endl;

        if (pilihan == "Admin" || pilihan == "admin" || pilihan == "1") {
            int maunyaadmin = -1;

            while (maunyaadmin != 0){
                cout << "\n========== MENU ADMIN ==========" << endl;
                cout << "1. Menambahkan lagu ke library" << endl;
                cout << "2. Melihat semua lagu di library" << endl;
                cout << "3. Mengubah data lagu di library" << endl;
                cout << "4. Menghapus data lagu di library" << endl;
                cout << "0. Kembali ke menu utama" << endl;
                cout << "Pilih: ";
                cin >> maunyaadmin;

                cout << endl;
                if (maunyaadmin == 1) {
                    addNewSong(library, lagu);
                } else if (maunyaadmin == 2) {
                    showAllSongs(library);
                } else if (maunyaadmin == 3) {
                    updateSong(library);
                } else if (maunyaadmin == 4) {
                    deleteSong(library);
                } else if (maunyaadmin == 0) {
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        }
        else if (pilihan == "User" || pilihan == "user" || pilihan == "2") {
            int maunyauser = -1;
            address song = nullptr;
            List daftarlagu;

            while(maunyauser != 0){
                cout << "\n========= MENU USER =========" << endl;
                cout << "1. Mencari lagu" << endl;
                cout << "2. Memutar lagu dari library" << endl;
                cout << "3. Menghentikan lagu" << endl;
                cout << "4. Memutar lagu selanjutnya" << endl;
                cout << "5. Memutar lagu sebelumnya" << endl;
                cout << "6. Menambahkan lagu ke playlist" << endl;
                cout << "7. Menghapus lagu dari playlist" << endl;
                cout << "8. Melihat isi playlist" << endl;
                cout << "0. Kembali ke menu utama" << endl;
                cout << "Pilih: ";
                cin >> maunyauser;

                cout << endl;
                if (maunyauser == 1) {
                    string pilihan;
                    cout << "1. ID" << endl;
                    cout << "2. Judul" << endl;
                    cout << "3. Penyanyi" << endl;
                    cout << "Cari lagu berdasarkan: ";
                    cin >> pilihan;

                    if (pilihan == "ID" || pilihan == "id" || pilihan == "1") {
                        string id;

                        cout << "Masukkan ID lagu: ";
                        cin >> id;
                        song = searchById(library, id);

                        if (song != nullptr) {
                            cout << "Lagu ditemukan!\n";
                            showSong(song);
                        } else {
                            cout << "Lagu tidak ditemukan!\n";
                        }
                    }
                    if (pilihan == "Judul" || pilihan == "judul" || pilihan == "2") {
                        string judul;

                        cout << "Masukkan judul lagu: ";
                        cin >> judul;
                        song = searchByTitle(library, judul);

                        if (song != nullptr) {
                            cout << "Lagu ditemukan!\n";
                            showSong(song);
                        } else {
                            cout << "Lagu tidak ditemukan!\n";
                        }
                    }
                    if (pilihan == "Penyanyi" || pilihan == "penyanyi" || pilihan == "3") {
                        string penyanyi;

                        cout << "Masukkan penyanyi: ";
                        cin >> penyanyi;
                        daftarlagu = searchBySinger(library, penyanyi);

                        if (!isEmpty(daftarlagu)) {
                            cout << "Lagu ditemukan!\n";
                            showAllSongs(daftarlagu);
                        } else {
                            cout << "Lagu tidak ditemukan!\n";
                        }
                    }
                } else if (maunyauser == 2) {
                    string pilihan;
                    cout << "1. ID" << endl;
                    cout << "2. Judul" << endl;
                    cout << "3. Penyanyi" << endl;
                    cout << "Cari lagu berdasarkan: ";
                    cin >> pilihan;

                    if (pilihan == "ID" || pilihan == "id" || pilihan == "1"){
                        string id;

                        cout << "Masukkan ID lagu: ";
                        cin >> id;
                        song = searchById(library, id);

                        if (song != nullptr) {
                            currentSong = song;
                            playSong(currentSong);
                        } else {
                            cout << "Lagu tidak ditemukan!\n";
                        }
                    } else if (pilihan == "Judul" || pilihan == "judul" || pilihan == "2"){
                        string judul;
                        cout << "Masukkan judul lagu: ";
                        cin >> judul;
                        song = searchByTitle(library, judul);

                        if (song != nullptr){
                            currentSong = song;
                            playSong(currentSong);
                        } else {
                            cout << "Lagu tidak ditemukan!\n";
                        }
                    } else if (pilihan == "Penyanyi" || pilihan == "penyanyi" || pilihan == "3") {
                        string penyanyi;
                        cout << "Masukkan penyanyi: ";
                        cin >> penyanyi;
                        List daftarlagu = searchBySinger(library, penyanyi);

                        if (isEmpty(daftarlagu)) {
                            cout << "Tidak ada lagu dari penyanyi tersebut.\n";
                        } else {
                            cout << "Daftar lagu oleh " << penyanyi << ": \n";
                            showAllSongs(daftarlagu);

                            string id;

                            cout << "Masukkan ID lagu: ";
                            cin >> id;
                            song = searchById(library, id);

                            currentSong = song;
                            playSong(currentSong);
                        }
                    } else {
                        cout << "Pilihan tidak valid.\n";
                    }
                } else if (maunyauser == 3) {
                    stopSong(currentSong);
                } else if (maunyauser == 4) {
                    nextSong(currentSong);
                } else if (maunyauser == 5) {
                    prevSong(currentSong);
                } else if (maunyauser == 6) {
                    string pilihan;
                    cout << "1. ID" << endl;
                    cout << "2. Judul" << endl;
                    cout << "3. Penyanyi" << endl;
                    cout << "Cari lagu berdasarkan: ";
                    cin >> pilihan;

                    address song = nullptr;

                    if (pilihan == "ID" || pilihan == "id" || pilihan == "1") {
                        string id;

                        cout << "Masukkan ID lagu: ";
                        cin >> id;
                        song = searchById(library, id);
                    } else if (pilihan == "Judul" || pilihan == "judul" || pilihan == "2") {
                        string judul;

                        cout << "Masukkan judul lagu: ";
                        cin >> judul;
                        song = searchByTitle(library, judul);
                    } else if (pilihan == "Penyanyi" || pilihan == "penyanyi" || pilihan == "3") {
                        string penyanyi;
                        cout << "Masukkan penyanyi: ";
                        cin >> penyanyi;
                        List daftarlagu = searchBySinger(library, penyanyi);

                        if (isEmpty(daftarlagu)) {
                            cout << "Tidak ada lagu dari penyanyi tersebut.\n";
                        } else {
                            cout << "Daftar lagu oleh " << penyanyi << ":\n";
                            showAllSongs(daftarlagu);

                            string id;

                            cout << "Masukkan ID lagu: ";
                            cin >> id;
                            song = searchById(library, id);
                        }
                    } else {
                        cout << "Pilihan tidak valid!\n";
                    }
                    if (song != nullptr){
                        addToPlaylist(playlist, song);
                    } else {
                        cout << "Lagu tidak ditemukan!\n";
                    }
                } else if (maunyauser == 7) {
                    removeFromPlaylist(playlist);
                } else if (maunyauser == 8) {
                    showPlaylist(playlist);
                } else if (maunyauser == 0) {
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        }
        else if (pilihan == "Keluar" || pilihan == "keluar" || pilihan == "0") {
            cout << "Terima kasih telah menggunakan aplikasi!\n";
            return 0;
        }
    }

    return 0;
}
