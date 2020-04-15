#include "InstructureRelation.h"

using namespace std;

int main()
{
    List instructure, course;
    string choice;

    createList(instructure);
    createList(course);

    menuList();
    cout << " Enter : ";
    cin >> choice;
    cout << endl;
    if (choice == "000"){
                   cout << "                   You have finished selecting the menu                    " << endl;
        printf("%-50s%\n", "|-------------------------------------------------------------------------|");
    }
    while(choice != "000"){
        if(choice == "1"){
            addInstructure(instructure);
        }else if(choice == "2"){
            showInstructorList(instructure);
        }else if(choice == "3"){
            addCourse(instructure, course);
        }else if (choice == "4"){
            showInstructorCourse(course,instructure);
        }else if (choice == "7"){
            showInstructorByCourse(instructure,course);
        }else {
            cout << "                       Input does not exist on menu"                        << endl;
        }
        menuList();
        cout << "Enter : ";
        cin >> choice;
        if (choice == "000"){
                   cout << "                   You have finished selecting the menu                    " << endl;
        printf("%-50s%\n", "|-------------------------------------------------------------------------|");
        cout << endl;
        }
    }

}
