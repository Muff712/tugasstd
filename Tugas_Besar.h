#ifndef TUGAS_BESAR_H_INCLUDED
#define TUGAS_BESAR_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elmlist *address;

struct lagu {
    string id;
    string judul;
    string penyanyi;
    string durasi;
};

typedef lagu infotype;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

struct User {
    string username;
    string password;
};

// menu
void menu();

// list
void createList(List &L);
bool isEmpty(List L);
address createElement(infotype x);
void insertLast(List &L, address p);

// admin
void addNewSong(List &L, infotype x);
void showSong(address p);
void initDummySongs(List &L);
void showAllSongs(List L);
void updateSong(List &L);
void deleteSong(List &L);
void deleteAddress(List &L, address p);

// search
address searchById(List L, string id);
address searchByTitle(List L, string judul);
List searchBySinger(List L, string penyanyi);

// user
void userSearchSong(List L);
void playSong(address &p);
void stopSong(address &p);
void nextSong(address &p);
void prevSong(address &p);
void addToPlaylist(List &playlist, address song);
void removeFromPlaylist(List &playlist);
void showPlaylist(List playlist);
void likedSongs(List &L, List &F);
void showLikedSongs(List F);
void showLikedSongs(List F);
void enqueueSong(List &queue, address song);
void playQueue(List &queue, address &currentSong);

// login
bool loginAdmin();
bool loginUser(string &username);
#endif // TUGAS_BESAR_H_INCLUDED
