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

address findRelation(List L, string name){
    address P = First(L);
    while(P != Nil){
        if(info(relation(P)).ID == name){
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
    printf("%-50s%\n", "| 000. Exit                                                               |");
    printf("%-50s%\n", "| 1. Add Instructor                                                       |");
    printf("%-50s%\n", "| 2. Show Instructor                                                      |");
    printf("%-50s%\n", "| 3. Add Course                                                           |");
    printf("%-50s%\n", "| 4. Show course taught                                                   |");
    printf("%-50s%\n", "| 5. Delete a certain course                                              |");
    printf("%-50s%\n", "| 6. Delete a certain instructor                                          |");
    printf("%-50s%\n", "| 7. Show instructor by course                                            |");
    printf("%-50s%\n", "| 8. Show instructor who teaching more then 3 course                      |");
    printf("%-50s%\n", "| 9. The highest number of courses taught by instructors                  |");
    printf("%-50s%\n", "| 10. The instructors who teach the most taught courses                   |");
    printf("%-50s%\n", "| 11. The average course taught by one instructor                         |");
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

    cout << "Enter instructor ID : ";
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

void showInstructorByCourse(List L,List I){
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-50s%\n", "|           Show instructor by course            |");
    printf("%-50s%\n", "|------------------------------------------------|");

    string name;

    cout << "Enter Course name : ";
    cin.ignore();
    getline(cin,name);
    if(findByName(I,name) == Nil){
        cout << "\nCourse does not exist\n" ;
    }else{
        if(relation(findByName(I,name)) == Nil){
            cout << "\nThe course is not taught by anyone" << endl;
        }else{
            cout << "\nThe course is taught by " << info(relation(findByName(I,name))).name << endl;
        }
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

void deleteFirst(List &L, address temp){
    if(First(L) == Last(L)){
        temp = First(L);
        First(L) = Nil;
        Last(L) = Nil;
    }else{
        temp = First(L);
        First(L) = next(temp);
        prev(First(L)) = Nil;
        next(temp) = Nil;
    }
}

void deleteAfter(address Prec, address &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(Prec)) = Prec;
    next(P) = Nil;
    prev(P) = Nil;
}

void deleteLast(List &L, address temp){
    if(First(L) == Last(L)){
        temp = First(L);
        First(L) = Nil;
        Last(L) = Nil;
    }else{
        temp = Last(L);
        Last(L) = prev(temp);
        next(Last(L)) = Nil;
        prev(temp) = Nil;
    }
}

void  deleteCourse(List L, List &I){
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-50s%\n", "|             Delete Certain Course              |");
    printf("%-50s%\n", "|------------------------------------------------|");
    string IDins, nameCourse;
    address temp;
    cin.ignore();
    cout << "Enter Course Name : ";
    getline(cin, nameCourse);
    if(findByName(I, nameCourse) == Nil){
        printf("%-50s%\n", "\n             No course registered\n");
    }else{
        cout << "Verification ID Instructor : ";
        getline(cin, IDins);
        if(info(relation(findByName(I, nameCourse))).ID == IDins){
            if(findByName(I, nameCourse) == First(I)){
                deleteFirst(I,temp);
                delete(temp);
                printf("%-50s%\n", "\n        Delete Course Success\n");
            }else if(findByName(I, nameCourse) == Last(I)){
                deleteLast(I,temp);
                delete(temp);
                printf("%-50s%\n", "\n        Delete Course Success\n");
            }else{
                deleteAfter(prev(findByName(I, nameCourse)), temp);
                delete(temp);
                printf("%-50s%\n", "\n        Delete Course Success\n");
            }
        }else{
            cout << printf("%-50s%\n", "\nVerification Failed, Delete Course Failed\n");
        }
    }
}

void deleteInstruction(List &L, List I){
    printf("%-50s%\n", "|------------------------------------------------|");
    printf("%-50s%\n", "|           Delete Certain Instruction           |");
    printf("%-50s%\n", "|------------------------------------------------|");
    string ID, name;
    address temp;
    cin.ignore();
    cout << "Enter Instructor ID : ";
    getline(cin, ID);
    if(findByID(L, ID) == Nil){
        printf("%-50s%\n", "\n             No Instruction registered\n");
    }else{
        if(findRelation(I, ID) != Nil){
            printf("%-50s%\n", "\nInstructor has relation, Delete instructor failed or Try delete course first!\n");
        }else{
            if(findByID(L, ID) == First(L)){
                deleteFirst(L,temp);
                delete(temp);
                printf("%-50s%\n", "\n        Delete Instruction Success\n");
            }else if(findByID(L, ID) == Last(L)){
                deleteLast(L,temp);
                delete(temp);
                printf("%-50s%\n", "\n        Delete Instruction Success\n");
            }else{
                deleteAfter(findByID(L, ID)->prev, temp);
                delete(temp);
                printf("%-50s%\n", "\n        Delete Instruction Success\n");
            }
        }
    }
}

void showInstructor3Course(List L,List I){
    address pCourse,pInstructor;
    bool condition,condition2  ;
    int counter;
    condition2=false;
    pInstructor = First(L);
    while (pInstructor != Nil){
         pCourse = First(I);
         counter = 0;
         condition = false ;
         while (pCourse != Nil && condition != true ){
            if (relation(pCourse) == pInstructor){
                counter++;
                if (counter == 4){
                    condition = true;
                    condition2 = true;
                    cout << "\nThe instructor who taught more then 3 course " <<  endl;
                    cout << info(pInstructor).name << endl;
                }
            }
            pCourse = next(pCourse);
         }

         pInstructor = next(pInstructor);
    }
    if (condition2 == false ){
        cout << "\nThere are no instructors who teach more than 3 course\n" << endl;
    }
}

void showMostCourses(List L,List I){
    address pCourse,pInstructor;
    int Max,sum;
    pInstructor = First(L);
    Max = 0;
    while (pInstructor != Nil){
         sum = 0;
         pCourse = First(I);
         while (pCourse != Nil){
            if (info(relation(pCourse)).name == info(pInstructor).name){
                sum++;
            }
            pCourse = next(pCourse);
         }
        if (Max < sum ){
            Max = sum ;
        }
        pInstructor = next(pInstructor);
    }
    if (Max == 0 ){
        cout << "\nNo courses have been made yet\n" << endl;
    }else {
        cout << "\nThe highest number of courses taught by one instructor is :" << Max << endl;
    }
}

void showInstructorTeachMostCourse(List L,List I){
    address pCourse,pInstructor,pMax;
    int Max,sum;
    pInstructor = First(L);
    pMax = pInstructor;
    Max = 0;
    while (pInstructor != Nil){
         sum = 0;
         pCourse = First(I);
         while (pCourse != Nil){
            if (info(relation(pCourse)).name == info(pInstructor).name){
                sum++;
            }
            pCourse = next(pCourse);
         }
        if (Max < sum ){
            Max = sum ;
            pMax = pInstructor ;
        }
        pInstructor = next(pInstructor);
    }
    if (Max == 0 ){
        cout << "\nNo courses have been made yet\n" << endl;
    }else {
        cout << "\nthe instructor who teaches the most courses : " << info(pMax).name << endl;
    }
}

void mean(List L,List I){
    address pCourse,pInstructor;
    int sumInstructor,sumCourse,mean;
    pInstructor = First(L);
    sumInstructor = 0;
    sumCourse = 0;
    while (pInstructor != Nil){
        sumInstructor++;
         pCourse = First(I);
         while (pCourse != Nil){
            if (info(relation(pCourse)).name == info(pInstructor).name){
                sumCourse++;
            }
            pCourse = next(pCourse);
         }
        pInstructor = next(pInstructor);
    }
    if (First(L)== Nil ){
        cout << "\nThe instructor have not been made yet\n" ;
    }else if (First(I) == Nil) {
        cout << "\nThe course has not been created\n" ;
    }else {
        mean = sumCourse/sumInstructor ;
        if (mean == 0){
            mean = 1;
        }
        cout << "\nThe average course taught by one instructor is : " << mean << endl;
    }
}
