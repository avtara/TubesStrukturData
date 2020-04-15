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
    cout << " Enter : ";
    cin >> choice;
    cout << endl;
    if (choice == "000"){
                   cout << "                   You have finished selecting the menu                    " ;
        printf("%-50s%\n", "\n|-------------------------------------------------------------------------|");
        cout <<  endl;
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
        }else if(choice == "5"){
            deleteCourse(instructure, course);
        }else if(choice == "6"){
            deleteInstruction(instructure, course);
        }else {
            cout << "                       Input does not exist on menu"                        << endl;
        }
        menuList();
        cout << "Enter : ";
        cin >> choice;
        cout << endl;
    }

}
