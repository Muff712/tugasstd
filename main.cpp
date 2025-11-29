#include <iostream>
#include "Tugas Besar.h"

using namespace std;

int main(){
    List L;
    address p;
    infotype lagu;

    createList(L);
    cout << "MENU PENGGUNA" << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "Siapa yang akan menggunakan aplikasi? ";
    string siapa;
    cin >> siapa;

    cout << endl;
    if (siapa == "Admin" || siapa == "admin") {
    cout << "MENU ADMIN" << endl;
    cout << "1. Menambahkan lagu ke library" << endl;
    cout << "2. Melihat semua lagu di library" << endl;
    cout << "3. Mengubah data lagu di library" << endl;
    cout << "4. Menghapus data lagu di library" << endl;

    cout << "Apa yang ingin dilakukan? ";
    int maunyaadmin;
    cin >> maunyaadmin;

    cout << endl;
    if (maunyaadmin == 1) {
        addNewSong(L, lagu);
    }
    }

    int menu;
    if (siapa == "User" || siapa == "user") {
    cout << "MENU USER\n" << endl;
    cout << "1. Mencari lagu berdasarkan data\n" << endl;
    cout << "2. Memutar lagu dari library maupun playlist\n" << endl;
    cout << "3. Menghentikan lagu dari library maupun playlist\n" << endl;
    cout << "4. Memutar lagu selanjutnya\n" << endl;
    cout << "5. Memutar lagu sebelumnya\n" << endl;
    cout << "6. Menambahkan lagu baru ke playlist\n" << endl;
    cout << "7. Menghapus lagu dari playlist\n" << endl;
    cout << "8. Melihat isi lagi di playlist\n" << endl;
    cout << "0. Keluar\n" << endl;
    cout << "Pilih: ";
    cin >> menu;
    }
}
