#include "TUBES_STD.h"

bool loginAdmin() {
    string password;
    cout << "Masukkan password admin: ";
    cin.ignore();
    getline(cin, password);
    
    if (password == "bukankah ini mykisah") {
        cout << "Login admin berhasil.\n";
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
        cout << "3. Hapus lagu (ID)\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            showAllSongs(library);
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
                cout << "ID lagu sudah ada. Lagu gagal ditambahkan.\n";
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
