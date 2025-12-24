#ifndef Tugas Besar_H
#define Tugas Besar_H
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

void DummySongs(List &L);

bool logInAdmin();
bool logInUser(string &username);
void menuAdmin(List &library);
void menuUser(List &library, List &favorite, List &queue);

void createList(List &L);
bool isEmpty(List L);
address createElement(infotype x);

void insertLast(List &L, address p);
void deleteAddress(List &L, address p);
void nextSong(address &p, List L);
void prevSong(address &p, List L);

void playSong(address &p);
void stopSong(address &p);
address searchById(List L, string id);
address searchByTitle(List L, string judul);
List searchBySinger(List L, string penyanyi);
address searchSong(List L);
void showSong(address p);
void showAllSongsLibrary(List L);

void addSongToUserPlaylist(List &playlistUser, address song);
void showAllSongsPlaylist(List L);
void menuPlaylistUser(List &library, List &favorite, List userPlaylists[], string namaPlaylist[], int &jumlahPlaylist, address &currentSong, List *&activeList);

void enqueueSong(List &queue, address song);
void playQueue(List &queue, address &currentSong);

#endif
