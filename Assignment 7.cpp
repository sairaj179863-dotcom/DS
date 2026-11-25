
#include <iostream>
#include <string>
using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
    string disease;

    Patient* next;
};

// Hash Table with 10 indexes
Patient* hashTable[10] = {NULL};

// Hash Function
int hashFunction(int id)
{
    return id % 10;
}

// Search Patient
Patient* searchPatient(int id)
{
    int index = hashFunction(id);

    Patient* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

// Register New Patient
void registerPatient()
{
    Patient* newPatient = new Patient;

    cout << "\nEnter Patient ID: ";
    cin >> newPatient->id;

    if (searchPatient(newPatient->id) != NULL)
    {
        cout << "\nPatient ID already exists!\n";
        delete newPatient;
        return;
    }

    cout << "Enter Patient Name: ";
    cin >> ws;
    getline(cin, newPatient->name);

    cout << "Enter Age: ";
    cin >> newPatient->age;

    cout << "Enter Disease: ";
    cin >> ws;
    getline(cin, newPatient->disease);

    int index = hashFunction(newPatient->id);

    // Insert at beginning of linked list
    newPatient->next = hashTable[index];
    hashTable[index] = newPatient;

    cout << "\nPatient registered successfully!\n";
}

// Search Patient Details
void displayPatient()
{
    int id;

    cout << "\nEnter Patient ID: ";
    cin >> id;

    Patient* temp = searchPatient(id);

    if (temp == NULL)
    {
        cout << "\nPatient not found!\n";
    }
    else
    {
        cout << "\nPatient Found!";
        cout << "\nPatient ID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nAge: " << temp->age;
        cout << "\nDisease: " << temp->disease << "\n";
    }
}

// Update Patient Information
void updatePatient()
{
    int id;

    cout << "\nEnter Patient ID to update: ";
    cin >> id;

    Patient* temp = searchPatient(id);

    if (temp == NULL)
    {
        cout << "\nPatient not found!\n";
        return;
    }

    cout << "Enter New Name: ";
    cin >> ws;
    getline(cin, temp->name);

    cout << "Enter New Age: ";
    cin >> temp->age;

    cout << "Enter New Disease: ";
    cin >> ws;
    getline(cin, temp->disease);

    cout << "\nPatient information updated successfully!\n";
}

// Discharge Patient (Delete)
void dischargePatient()
{
    int id;

    cout << "\nEnter Patient ID to discharge: ";
    cin >> id;

    int index = hashFunction(id);

    Patient* temp = hashTable[index];
    Patient* previous = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (previous == NULL)
            {
                hashTable[index] = temp->next;
            }
            else
            {
                previous->next = temp->next;
            }

            delete temp;

            cout << "\nPatient discharged successfully!\n";
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "\nPatient not found!\n";
}

// Display All Patients
void displayAllPatients()
{
    bool found = false;

    cout << "\n--- All Patient Records ---\n";

    for (int i = 0; i < 10; i++)
    {
        Patient* temp = hashTable[i];

        while (temp != NULL)
        {
            found = true;

            cout << "\nPatient ID: " << temp->id;
            cout << "\nName: " << temp->name;
            cout << "\nAge: " << temp->age;
            cout << "\nDisease: " << temp->disease << "\n";

            temp = temp->next;
        }
    }

    if (found == false)
    {
        cout << "\nNo patient records available!\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== HOSPITAL PATIENT MANAGEMENT =====";
        cout << "\n1. Register New Patient";
        cout << "\n2. Search Patient";
        cout << "\n3. Update Patient";
        cout << "\n4. Discharge Patient";
        cout << "\n5. Display All Patients";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            registerPatient();

        else if (choice == 2)
            displayPatient();

        else if (choice == 3)
            updatePatient();

        else if (choice == 4)
            dischargePatient();

        else if (choice == 5)
            displayAllPatients();

        else if (choice == 0)
            cout << "\nExiting system...\n";

        else
            cout << "\nInvalid choice!\n";

    } while (choice != 0);

    // Free dynamically allocated memory
    for (int i = 0; i < 10; i++)
    {
        Patient* temp = hashTable[i];

        while (temp != NULL)
        {
            Patient* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    return 0;
}
