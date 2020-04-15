#include "InstructureRelation.h"

using namespace std;

int main()
{
    List instructure, course;
    address temp;
    string choice;

    createList(instructure);
    createList(course);

    menuList();
    cout << "Enter :";
    cin >> choice;
    cout << endl;
    while(choice != "0"){
        if(choice == "1"){
            addInstructure(instructure);
        }else if(choice == "2"){
            showInstructorList(instructure);
        }else if(choice == "3"){
            addCourse(instructure, course);
        }else if (choice == "4"){
            showInstructorCourse(course,instructure);
        }
        menuList();
        cout << "Enter : ";
        cin >> choice;
        cout << endl;
    }
}
