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

void menu();
void createList(List &L);
bool isEmpty(List L);
address createElement(infotype x);
void insertLast(List &L, address p);
void addNewSong(List &L, infotype x);
address findSong(List L, string id);
void deleteAddress(List &L, address p);
void showAllSongs(List L);
void updateSong(List &L);
void deleteSong(List &L);
void userSearchSong(List L);
void playSong(address &p);
void stopSong(address &p);
void nextSong(address &p);
void prevSong(address &p);
void addToPlaylist(List &playlist, address song);
void removeFromPlaylist(List &playlist);
void showPlaylist(List playlist);

#endif // TUGAS_BESAR_H_INCLUDED
