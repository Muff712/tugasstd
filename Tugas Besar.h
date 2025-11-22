#ifndef TUGAS_BESAR_H_INCLUDED
#define TUGAS_BESAR_H_INCLUDED
#include <iostream>

typedef lagu infotype;
typedef struct elmlist *address;

struct lagu {
    int id;
    char judul;
    char penyanyi;
    char durasi;
};

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};



#endif // TUGAS_BESAR_H_INCLUDED
