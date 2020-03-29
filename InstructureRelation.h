#ifndef INSTRUCTURERELATION_H_INCLUDED
#define INSTRUCTURERELATION_H_INCLUDED

#define Nil NULL
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#include <iostream>
#include <cstdlib>

using namespace std;


typedef struct elmlist *address;

struct infotype{
    string ID, name;
    int total;
};

struct elmlist {
    infotype info;
    address next;
    address prev;
    address relation;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
bool isEmpty(List L);


#endif // INSTRUCTURERELATION_H_INCLUDED
