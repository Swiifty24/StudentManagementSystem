#include <iostream>

using namespace std;
//assignment

struct Student
{
   int StudentId;
   string firstName, lastName, course;
   float GPA;
};

void display_menu()
{
    system("cls");
    cout << "====Welcome to our School====\n";
    cout << "1. Add A student\n";
    cout << "2. Edit A student\n";
    cout << "3. Delete A student\n";
    cout << "4. View A student \n";
    cout << "5. Exit our school\n";
}

void addStudent (Student students[], int studentAdder)
{
    Student studentCheck;
    char choice;
    system("cls");

    cout << "==Adding A student==\n";
    bool found = false;

     for (int i = 0; i < studentAdder; i++)
    {
        if (students[i].StudentId == studentCheck.StudentId)
        {
            cout << "The following student is already in the program";
            found = true;
        }
    }

    cout << "====Enter Student Data====\n";
    cout << "\nEnter Student id\n";
    cin.ignore();
    cin >> studentCheck.StudentId;

    if (studentAdder >= 100)
    {
        cout << "The number of students has been met. Unable to add more";
    }
    if(!found)
    {
        cout << "Enter Student's First Name\n";
        cin >> students[studentAdder].firstName;
        cout << "Enter Student's Last Name\n";
        cin >> students[studentAdder].lastName;
        cout << "Enter Student's Course\n";
        cin >> students[studentAdder].course;
        cout << "Enter Student's Previous GPA: ";
        cin >> students[studentAdder].GPA;

        studentAdder++;
        students[studentAdder] = studentCheck;
        cout << "Student Added Successfully";
    }
}

void displayRecords (Student students[], int studentAdder, int studentid)
{
    bool found = false;
    for (int i = 0; i < studentAdder; i++)
    {
        if (students[i].StudentId == studentid)
        {
            cout << "ID: " << students[i].StudentId << '\n';
            cout << "First Name: " << students[i].firstName << '\n';
            cout << "Last Name: " << students[i].lastName << '\n';
            cout << "Course: " << students[i].course << '\n';
            cout << "GPA: " << students[i].GPA << '\n';
            cout << "============================================\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "There are no students in the program";
    }
}
void editStudent (Student students[], int studentAdder)
{
    int studentid;

    system("cls");

    cout << "======EDIT A STUDENT======\n\n";
    cout << "----Edit A student----";
    cout << "\nEnter Student id: ";
    cin >> studentid;
    bool found = false;

    if (studentAdder == 0)
    {
    cout << "There are no students\n";
    return;
    }

    for (int i = 0; i < studentAdder; i++)
    {
        if (students[i].StudentId == studentid)
        {
            displayRecords(students, studentid, studentAdder);
            cout << "\nEnter new ID: ";
            cin >> students[i].StudentId;
            cout << "\nEnter First Name: ";
            cin >> students[i].firstName;
            cout << "\nEnter Last Name: ";
            cin >> students[i].lastName;
            cout << "\nEnter New Course: ";
            cin >> students[i].course;
            cout << "\nEnter New GPA: ";
            cin >> students[i].GPA;
            cout << "\n\n =====Student Has been updated=====";
            found = true;
        }
    }

}

void deleteStudent(Student students[], int studentAdder)
{
    int studentid;

    system("cls");
    while (true)
    {
        cout << "\n=======Student Removal========\n";
        cout << "Enter Student ID to search: ";
        cin >> studentid;
        bool found = false;

        if (studentAdder == 0)
        {
            cout << "\n No available Records";
            return;

        }

        for (int i = 0; i < studentAdder; i++)
        {
            if (students[i].StudentId == studentid)
            {
                displayRecords(students, studentAdder, studentid);
                found = true;

                for (int j = i; j < studentAdder - 1; i++)
                {
                    students[j] = students[j + 1];
                }
                cout << "Student has been deleted in the program";
                studentAdder--;
                break;
            }
        }

        if (!found)
        {
            cout << "Student has not been registered";
        }
        break;
    }
}

void viewStudent (Student students[], int studentAdder)
{
    system("cls");
    if(studentAdder == 0)
    {
        cout << "There are no students";
    }
    else
    {
        int choose;
    do
    {
        cout << "How would you like to view the list of students?\n";
        cout << "1. Alphabetically\n";
        cout << "2. GPA\n";
        cout << "3. Return to menu\n";
        cout << "Enter Choice: ";
        cin >> choose;

            switch (choose)
            {
            case 1:
                {
                    if(studentAdder == 0)
                    {
                        cout << "there are no students in the program recently.";
                    }
                    else
                    {

                    }
                    cout << "Viewing the List of Students Alphabetically";

                    for (int i = 0; i < studentAdder - 1; i++)
                    {
                        for(int j = 0; j < studentAdder - i - 1; j++)
                        {
                            if (students[j].lastName > students[j + 1].lastName)
                            {
                                Student temp = students[j];
                                students[j] = students[j + 1];
                                students[j + 1] = temp;
                            }
                        }
                    }

                    for (int i = 0; i < studentAdder; i++)
                    {
                        cout <<"\nStudent ID: " << students[i].StudentId;
                        cout <<"\nFirst Name: " << students[i].firstName;
                        cout <<"\nLast Name: " << students[i].lastName;
                        cout <<"\nCourse: " << students[i].course;
                        cout <<"\nGPA: " << students[i].GPA;
                        cout <<"\n==========================================";
                    }
                    break;
                }
            case 2:
                {
                    cout << "Viewing the list of Students through their GPA";

                    for (int i = 0; i < studentAdder - 1; i++)
                    {
                        for(int j = 0; j < studentAdder - i - 1; j++)
                        {
                            if (students[j].StudentId > students[j + 1].StudentId)
                            {
                                Student temp = students[j];
                                students[j] = students[j + 1];
                                students[j + 1] = temp;
                            }
                        }
                    }

                    for (int i = 0; i < studentAdder; i++)
                    {
                        cout <<"\nStudent ID: " << students[i].StudentId;
                        cout <<"\nFirst Name: " << students[i].firstName;
                        cout <<"\nLast Name: " << students[i].lastName;
                        cout <<"\nCourse: " << students[i].course;
                        cout <<"\nGPA: " << students[i].GPA;
                        cout <<"\n==========================================";
                    }
                    break;
                }
            case 3:
                {
                    cout << "returning to menu";
                    break;
                }
            default:
                {
                    cout << "Invalid input try again";
                    break;
                }
            }
        }
        while(choose != 3);
    }
}

int main()
{
    Student students[100];
    int studentAdder = 0;
    int choice;

    do
    {
        display_menu();
        cin >> choice;

        switch (choice)
        {

            case 1:
                {
                    addStudent(students, studentAdder);
                    studentAdder++;
                    break;
                }
            case 2:
                {
                    editStudent(students, studentAdder);
                    break;
                }
            case 3:
                {
                    deleteStudent(students, studentAdder);
                    studentAdder--;
                    break;
                }
            case 4:
                {

                    viewStudent(students, studentAdder);
                    break;
                }
            case 5:
                {
                    cout << "Thank you for attending, see you soon!";
                    return 0;
                    break;
                }
            default:
                {
                    cout << "\nInvalid Option please try again\n";
                    break;
                }
        }
    }
    while(choice != 5);
    return 0;
}


