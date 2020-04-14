#include "InstructureRelation.h"

void createList(List &L){
    First(L) = Nil;
    Last(L) = Nil;
}

bool isEmpty(List L){
    return First(L) == Nil and Last(L) == Nil;
}

address createElm(string ID,string name){
    address P = new elmlist;
    next(P) = Nil;
    prev(P) = Nil;
    relation(P) = Nil;
    info(P).ID = ID;
    info(P).name = name;

    return P;
}

void insertLast(List &L, address P) {
    if(Last(L) == NULL) {
        First(L) = P;
        Last(L) = P;
    }else {
        next(Last(L)) = P;
        prev(P) = Last(L);
        Last(L) = P;
    }
}

void printList(List L){
    address P = First(L);
    while (P != NULL) {
        cout << info(P).name << " ";
        P = next(P);
    }
    cout << endl;
}

address findByName(List L, string name){
    address P = First(L);
    while(P != Nil){
        if(info(P).name == name){
            return P;
        }
        P = next(P);
    }
    return Nil;
}

address findByID(List L, string ID){
    address P = First(L);
    while(P != Nil){
        if(info(P).ID == ID){
            return P;
        }
        P = next(P);
    }
    return Nil;
}

void connecting(address P, address Q){
    relation(P) = Q;
}

void addInstructure(List &L){
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-50s%\n", "|               Add Instructor                   |");
    printf("%-50s%\n", "|------------------------------------------------|");
    string name, ID, choice = "-1";
    cout << "ID : ";
    cin >> ID;
    cin.ignore();
    if(findByID(L,ID) == Nil){
        cout << "Name : ";
        getline(cin,name);
        insertLast(L, createElm(ID, name));
        cout << "\nThe instructor was successfully registered\n" << endl;
    }else{
        cout << "\nInstructor ID already registered, can't add anymore\n" << endl;
    }
}

void showInstructorList(List L){
    address P = First(L);
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-25s|%-25s%\n", "ID Instructor", "Name");
    printf("%-50s%\n", "|------------------------------------------------|");
    if(P == Nil){
        printf("%-50s%\n", "             No instructor registered\n");
    }
    while(P != Nil){
        printf("%-25s|%-25s%\n", info(P).ID.c_str(), info(P).name.c_str());
        P = next(P);
    }
    cout << endl;
}

void menuList(){
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-50s%\n", "|              Instruktor  System                |");
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-50s%\n", "| 1. Add Instructor                              |");
    printf("%-50s%\n", "| 2. Show Instructor                             |");
    printf("%-50s%\n", "|------------------------------------------------|");
}
