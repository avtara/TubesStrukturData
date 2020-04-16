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
    //int sumRelation;
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
address findByID(List L, string ID);
address findRelation(List L, string name);
int totalCourse(List L);
void deleteFirst(List &L, address temp);
void deleteAfter(address Prec, address &p);
void deleteLast(List &L, address temp);

void addInstructure(List &L);
void showInstructorList(List L);
void addCourse(List L, List &I);
void menuList();
void showInstructorByCourse(List L,List I);

void deleteCourse(List L, List &I);
void deleteInstruction(List &L, List I);

void showInstructorCourse(List I,List L);
void deleteInstruction(List &L, List I);

#endif // INSTRUCTURERELATION_H_INCLUDED
