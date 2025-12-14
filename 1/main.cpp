#include "TUBES_STD.h"

int main() {
    List library, favorite, queue;
    string pilihan;

    createList(library);
    createList(favorite);
    createList(queue);

    initDummySongs(library);

    while (true) {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == "1") {
            if (loginAdmin()) {
                menuAdmin(library);
            } else {
                cout << "Login admin gagal.\n";
            }
        }
        else if (pilihan == "2") {
            string username;
            if (loginUser(username)) {
                menuUser(library, favorite, queue);
            } else {
                cout << "Login user gagal.\n";
            }
        }
        else if (pilihan == "0") {
            cout << "Program selesai.\n";
            return 0;
        }
    }
}
