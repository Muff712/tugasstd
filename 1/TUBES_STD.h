#ifndef TUBES_STD_H
#define TUBES_STD_H
#include <iostream>
using namespace std;


typedef struct elmlist *address;


struct Lagu {
string id;
string judul;
string penyanyi;
string durasi;
};


typedef Lagu infotype;


struct elmlist {
infotype info;
address next;
address prev;
};


struct List {
address first;
address last;
};


struct UserPlaylist {
string nama;
List lagu;
};


void createList(List &L);
bool isEmpty(List L);
address createElement(infotype x);
void insertLast(List &L, address p);

address searchByTitle(List L, string judul);
address searchById(List L, string id);

void showAllSongs(List L);
void insertLast(List &L, address p);
void deleteAddress(List &L, address p);

void showSong(address p);
void showAllSongs(List L);
void playSong(address &p);
void stopSong(address &p);
void nextSong(address &p);
void prevSong(address &p);


void enqueueSong(List &queue, address song);
void playQueue(List &queue, address &currentSong);

bool loginAdmin();
bool loginUser(string &username);

void menuAdmin(List &library);
void menuUser(List &library, List &favorite, List &queue);

void initDummySongs(List &L);


#endif