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
    string name, ID;
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
    printf("%-50s%\n", "|-------------------------------------------------------------------------|");
    printf("%-50s%\n", "|                           Instructor System                             |");
    printf("%-50s%\n", "|-------------------------------------------------------------------------|");
    printf("%-50s%\n", "| 1. Add Instructor                                                       |");
    printf("%-50s%\n", "| 2. Show Instructor                                                      |");
    printf("%-50s%\n", "| 3. Add Course                                                           |");
    printf("%-50s%\n", "| 4. Show course taught                                                   |");
    printf("%-50s%\n", "| 5. Delete a certain course                                              |");
    printf("%-50s%\n", "| 6. Delete a certain instructor                                          |");
    printf("%-50s%\n", "| 7. Show instructor by course                                            |");
    printf("%-50s%\n", "| 8. Show instructor who teaching more then 3 course                      |");
    printf("%-50s%\n", "| 9. Find the average number of courses taught by an instructor           |");
    printf("%-50s%\n", "| 10. Find the greatest number of courses taught by a same instructor     |");
    printf("%-50s%\n", "|-------------------------------------------------------------------------|");
}

int totalCourse(List L){
    int total = 0;
    address P = First(L);
    while(P != Nil){
        total++;
        P = next(P);
    }
    return total;
}

void showInstructorCourse(List I,List L){
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-50s%\n", "|            Show course by instructor           |");
    printf("%-50s%\n", "|------------------------------------------------|");

    address P,check;
    string IDins;
    bool condition;
    condition = false;
    cout << "Enter instructor ID :";
    cin.ignore();
    getline(cin,IDins);
    check = findByID(L,IDins);
    P = First(I);
    printf("%-25s|%-25s%\n", "Instructor Name", "Course Name");
    printf("%-50s%\n", "|------------------------------------------------|");
    while (P != Nil && check != Nil){
        if (info(relation(P)).ID == IDins) {
            printf("%-25s|%-25s%\n", info(relation(P)).name.c_str(), info(P).name.c_str());
            condition = true;
        }
    P = next(P);
    }
    cout << endl;
    if (check == Nil ){
        cout << "          The instructor does not exist\n" << endl;
    } else if (condition == false){
        cout << "      The instructor does not teach course\n" << endl;
    }
}

void addCourse(List L, List &I){
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-50s%\n", "|                 Add Course                     |");
    printf("%-50s%\n", "|------------------------------------------------|");
    string IDins,ID,course;
    cout << "Instuctor ID : ";
    cin.ignore();
    getline(cin, IDins);
    if(findByID(L, IDins) == Nil){
        cout << "\ninstructor not found, cannot add course\n" << endl;
    }else{
        cout << "Course name : ";
        getline(cin, course);
        ID = course[0] + course[1] + course[2] + "32910";
        insertLast(I, createElm(ID, course));
        connecting(Last(I), findByID(L, IDins));
        cout << "\nThe course was successfully registered\n" << endl;
    }
}
