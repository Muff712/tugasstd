#include "Tugas Besar.h"
#include <iostream>
using namespace std;

int main() {
    List library, favorite, queue;
    string pilihan;

    createList(library);
    createList(favorite);
    createList(queue);

    DummySongs(library);

    while (true) {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == "1") {
            if (logInAdmin()) {
                menuAdmin(library);
            } else {
                cout << "Log in admin gagal.\n";
            }
        } else if (pilihan == "2") {
            string username;

            if (logInUser(username)) {
                menuUser(library, favorite, queue);
            } else {
                cout << "Login user gagal.\n";
            }
        } else if (pilihan == "0") {
            cout << "Program selesai.\n";
            return 0;
        }
    }
}
