#include <iostream>
#include "Tugas_Besar.h"

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
            int maunyaadmin = -1; // ini yang buat biar enggak langsung keluar dari menu admin

            while(maunyaadmin != 0){
                cout << "\n=== MENU ADMIN ===" << endl;
                cout << "1. Menambahkan lagu ke library" << endl;
                cout << "2. Melihat semua lagu di library" << endl;
                cout << "3. Mengubah data lagu di library" << endl;
                cout << "4. Menghapus data lagu di library" << endl;
                cout << "0. Kembali ke menu utama" << endl;
                cout << "10. keluar apk";
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
                    cout << "Kembali ke menu utama.\n";
                } else {
                    cout << "terimkasih telah menggunakan apk enggak jelas ini.\n";
                    return 0;
                }
            }
        }
        else if (pilihan == "User" || pilihan == "user" || pilihan == "2") {
            int maunyauser = -1;

            while(maunyauser != 0){
                cout << "\n=== MENU USER ===" << endl;
                cout << "1. Mencari lagu berdasarkan ID" << endl;
                cout << "2. Memutar lagu dari library" << endl;
                cout << "3. Menghentikan lagu" << endl;
                cout << "4. Memutar lagu selanjutnya" << endl;
                cout << "5. Memutar lagu sebelumnya" << endl;
                cout << "6. Menambahkan lagu ke playlist" << endl;
                cout << "7. Menghapus lagu dari playlist" << endl;
                cout << "8. Melihat isi playlist" << endl;
                cout << "0. Kembali ke menu utama" << endl;
                cout << "10. keluar apk";
                cout << "Pilih: ";
                cin >> maunyauser;

                cout << endl;
                if (maunyauser == 1) {
                    userSearchSong(library);
                } else if (maunyauser == 2) {
                    int pilihan;
                    cout << "Cari lagu berdasarkan:\n";
                    cout << "1. Judul Lagu\n";
                    cout << "2. ID Lagu\n";
                    cout << "Pilih: ";
                    cin >> pilihan;

                    if(pilihan == 1){
                        string judul;
                        cout << "Masukkan judul lagu: ";
                        cin >> judul;

                        address temp = library.first;
                        bool found = false;
                        while(temp != nullptr && !found){
                            if(temp->info.judul == judul){
                                currentSong = temp;
                                playSong(currentSong);
                                found = true;
                            }
                            temp = temp->next;
                        }
                        if(!found){
                            cout << "Lagu tidak ditemukan.\n";
                        }
                    } else if(pilihan == 2){
                        string id;
                        cout << "Masukkan ID lagu: ";
                        cin >> id;
                        currentSong = findSong(library, id);
                        if(currentSong != nullptr){
                            playSong(currentSong);
                        } else {
                            cout << "Lagu tidak ditemukan.\n";
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
                    int pilihan;
                    cout << "Cari lagu yang ingin ditambahkan ke playlist berdasarkan:\n";
                    cout << "1. Judul Lagu\n";
                    cout << "2. ID Lagu\n";
                    cout << "Pilih: ";
                    cin >> pilihan;

                    address song = nullptr;

                    if(pilihan == 1){
                        string judul;
                        cout << "Masukkan judul lagu: ";
                        cin >> judul;

                        address temp = library.first;
                        while(temp != nullptr && song == nullptr){
                            if(temp->info.judul == judul){
                                song = temp;
                            }
                            temp = temp->next;
                        }
                    } else if(pilihan == 2){
                        string id;
                        cout << "Masukkan ID lagu: ";
                        cin >> id;
                        song = findSong(library, id);
                    } else {
                        cout << "Pilihan tidak valid.\n";
                    }

                    if(song != nullptr){
                        addToPlaylist(playlist, song);
                    } else {
                        cout << "Lagu tidak ditemukan di library.\n";
                    }
                } else if (maunyauser == 7) {
                    removeFromPlaylist(playlist);
                } else if (maunyauser == 8) {
                    showPlaylist(playlist);
                } else if (maunyauser == 0) {
                    cout << "Kembali ke menu utama.\n";
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        }
        else if (pilihan == "0" || pilihan == "keluar" || pilihan == "Keluar") {
            cout << "Terima kasih telah menggunakan aplikasi!\n";
            return 0;
        }
        else {
            cout << "terimkasih telah menggunakan apk enggak jelas ini.\n";
            return 0;
        }
    }

    return 0;
}
