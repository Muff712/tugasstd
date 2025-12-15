#include "Tugas Besar.h"

bool logInAdmin() {
    string password;
    cout << "Masukkan password admin: ";
    getline(cin, password);

    if (password == "bukankah ini mykisah") {
        cout << "Admin berhasil masuk.\n";
        return true;
    } else {
        cout << "Password salah.\n";
        return false;
    }
}

void menuAdmin(List &library) {
    int pilih = -1;

    while (pilih != 0) {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Lihat semua lagu\n";
        cout << "2. Tambah lagu\n";
        cout << "3. Hapus lagu\n";
        cout << "0. Log Out\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            showAllSongsLibrary(library);
        }

        else if (pilih == 2) {
            infotype x;

            cout << "Masukkan ID Lagu    : ";
            getline(cin, x.id);
            cout << "Masukkan Judul Lagu : ";
            getline(cin, x.judul);
            cout << "Masukkan Penyanyi   : ";
            getline(cin, x.penyanyi);
            cout << "Masukkan Durasi     : ";
            getline(cin, x.durasi);

            address cek = searchById(library, x.id);

            if (cek != nullptr) {
                cout << "Lagu sudah ada. Lagu gagal ditambahkan.\n";
            } else {
                address p = createElement(x);
                insertLast(library, p);
                cout << "Lagu berhasil ditambahkan.\n";
            }
        }

        else if (pilih == 3) {
            string id;
            cout << "Masukkan ID lagu: ";
            getline(cin, id);

            address target = searchById(library, id);

            if (target != nullptr) {
                deleteAddress(library, target);
                cout << "Lagu berhasil dihapus.\n";
            } else {
                cout << "Lagu tidak ditemukan.\n";
            }
        }
    }
}
