
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int roll;
    string name;
    string program;
    float marks;
};

Student s[100];
int n = 0;

// Add Student
void addStudent()
{
    cout << "\nEnter Roll Number: ";
    cin >> s[n].roll;

    cout << "Enter Name: ";
    cin >> ws;
    getline(cin, s[n].name);

    cout << "Enter Program: ";
    getline(cin, s[n].program);

    cout << "Enter Marks: ";
    cin >> s[n].marks;

    n++;

    cout << "\nStudent added successfully!\n";
}

// Display Students
void displayStudents()
{
    if (n == 0)
    {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nRoll Number: " << s[i].roll;
        cout << "\nName: " << s[i].name;
        cout << "\nProgram: " << s[i].program;
        cout << "\nMarks: " << s[i].marks << "\n";
    }
}

// Search Student
void searchStudent()
{
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == roll)
        {
            cout << "\nStudent Found!";
            cout << "\nName: " << s[i].name;
            cout << "\nProgram: " << s[i].program;
            cout << "\nMarks: " << s[i].marks << "\n";
            return;
        }
    }

    cout << "\nStudent not found!\n";
}

// Update Student
void updateStudent()
{
    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == roll)
        {
            cout << "Enter New Name: ";
            cin >> ws;
            getline(cin, s[i].name);

            cout << "Enter New Program: ";
            getline(cin, s[i].program);

            cout << "Enter New Marks: ";
            cin >> s[i].marks;

            cout << "\nRecord updated successfully!\n";
            return;
        }
    }

    cout << "\nStudent not found!\n";
}

// Delete Student
void deleteStudent()
{
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == roll)
        {
            for (int j = i; j < n - 1; j++)
            {
                s[j] = s[j + 1];
            }

            n--;

            cout << "\nStudent deleted successfully!\n";
            return;
        }
    }

    cout << "\nStudent not found!\n";
}

// Sort Students
void sortStudents()
{
    int choice;

    cout << "\n1. Sort by Roll Number";
    cout << "\n2. Sort by Name";
    cout << "\n3. Sort by Total Marks";
    cout << "\nEnter choice: ";
    cin >> choice;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            bool swapNeeded = false;

            if (choice == 1 && s[j].roll > s[j + 1].roll)
                swapNeeded = true;

            else if (choice == 2 && s[j].name > s[j + 1].name)
                swapNeeded = true;

            else if (choice == 3 && s[j].marks < s[j + 1].marks)
                swapNeeded = true;

            if (swapNeeded)
            {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    cout << "\nRecords sorted successfully!\n";
    displayStudents();
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Sort Students";
        cout << "\n0. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent();

        else if (choice == 2)
            displayStudents();

        else if (choice == 3)
            searchStudent();

        else if (choice == 4)
            updateStudent();

        else if (choice == 5)
            deleteStudent();

        else if (choice == 6)
            sortStudents();

        else if (choice == 0)
            cout << "\nExiting program...\n";

        else
            cout << "\nInvalid choice!\n";

    } while (choice != 0);

    return 0;
}
