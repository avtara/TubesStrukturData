#ifndef INSTRUCTURERELATION_H_INCLUDED
#define INSTRUCTURERELATION_H_INCLUDED

#define Nil NULL
#define First(L) L.First
#define Last(L) L.Last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define relation(P) P->relation
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>

using namespace std;


typedef struct elmlist *address;

struct infotype{
    string ID, name;
};

struct elmlist {
    infotype info;
    address next;
    address prev;
    address relation;
};

struct List {
    address First;
    address Last;
};

void createList(List &L);
bool isEmpty(List L);
address createElm(string ID, string name);
void insertLast(List &L, address P);
void printList(List L);
address findByName(List L, string name);
void connecting(address P, address Q);

void addInstructure(List &L);
void showInstructorList(List L);
void menuList();



#endif // INSTRUCTURERELATION_H_INCLUDED
