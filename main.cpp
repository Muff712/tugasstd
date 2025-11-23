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

    if (siapa == "User" || siapa == "user") {
    cout << "MENU USER" << endl;
    cout << "1. Mencari lagu berdasarkan data" << endl;
    cout << "2. Memutar lagu atau menghentikan lagu dari library maupun playlist" << endl;
    cout << "3. Memutar lagu selanjutnya atau sebelumnya" << endl;
    cout << "4. Menambahkan lagu baru ke playlist" << endl;
    cout << "5. Menghapus lagu dari playlist" << endl;
    cout << "6. Melihat isi lagi di playlist" << endl;
    }
}
