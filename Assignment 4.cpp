
#include <iostream>
#include <string>
using namespace std;

struct Request
{
    int id;
    string name;
    string issue;
    int priority;
};

// Normal Queue
Request normalQueue[100];
int front = 0, rear = -1;

// Priority Queue
Request priorityQueue[100];
int priorityCount = 0;

// Stack for Resolved Requests
Request history[100];
int top = -1;

// Add Normal Request
void addNormalRequest()
{
    if (rear == 99)
    {
        cout << "\nNormal queue is full!\n";
        return;
    }

    rear++;

    cout << "\nEnter Request ID: ";
    cin >> normalQueue[rear].id;

    cout << "Enter Customer Name: ";
    cin >> ws;
    getline(cin, normalQueue[rear].name);

    cout << "Enter Issue: ";
    getline(cin, normalQueue[rear].issue);

    cout << "\nNormal request added to queue!\n";
}

// Add Urgent Request
void addUrgentRequest()
{
    if (priorityCount == 100)
    {
        cout << "\nPriority queue is full!\n";
        return;
    }

    Request r;

    cout << "\nEnter Request ID: ";
    cin >> r.id;

    cout << "Enter Customer Name: ";
    cin >> ws;
    getline(cin, r.name);

    cout << "Enter Issue: ";
    getline(cin, r.issue);

    cout << "Enter Priority (1-5, 5 is highest): ";
    cin >> r.priority;

    if (r.priority < 1 || r.priority > 5)
    {
        cout << "\nInvalid priority!\n";
        return;
    }

    int i = priorityCount - 1;

    while (i >= 0 && priorityQueue[i].priority < r.priority)
    {
        priorityQueue[i + 1] = priorityQueue[i];
        i--;
    }

    priorityQueue[i + 1] = r;
    priorityCount++;

    cout << "\nUrgent request added successfully!\n";
}

// Push Request into Stack
void pushHistory(Request r)
{
    if (top == 99)
    {
        cout << "\nHistory stack is full!\n";
        return;
    }

    top++;
    history[top] = r;
}

// Process Normal Queue
void processNormalRequest()
{
    if (front > rear)
    {
        cout << "\nNo normal requests available!\n";
        return;
    }

    Request r = normalQueue[front];

    cout << "\nProcessing Normal Request";
    cout << "\nRequest ID: " << r.id;
    cout << "\nCustomer: " << r.name;
    cout << "\nIssue: " << r.issue;

    pushHistory(r);

    front++;

    if (front > rear)
    {
        front = 0;
        rear = -1;
    }

    cout << "\nRequest resolved and added to history!\n";
}

// Process Priority Queue
void processUrgentRequest()
{
    if (priorityCount == 0)
    {
        cout << "\nNo urgent requests available!\n";
        return;
    }

    Request r = priorityQueue[0];

    cout << "\nProcessing Urgent Request";
    cout << "\nRequest ID: " << r.id;
    cout << "\nCustomer: " << r.name;
    cout << "\nIssue: " << r.issue;
    cout << "\nPriority: " << r.priority;

    pushHistory(r);

    for (int i = 0; i < priorityCount - 1; i++)
    {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    priorityCount--;

    cout << "\nUrgent request resolved and added to history!\n";
}

// Display Resolved History
void displayHistory()
{
    if (top == -1)
    {
        cout << "\nNo resolved requests available!\n";
        return;
    }

    cout << "\n--- Resolved Request History (Stack) ---\n";

    for (int i = top; i >= 0; i--)
    {
        cout << "\nRequest ID: " << history[i].id;
        cout << "\nCustomer: " << history[i].name;
        cout << "\nIssue: " << history[i].issue << "\n";
    }
}

// Recursive IVR System
void IVR()
{
    int choice;

    cout << "\n===== CUSTOMER IVR SYSTEM =====";
    cout << "\n1. Billing Support";
    cout << "\n2. Technical Support";
    cout << "\n3. Product Information";
    cout << "\n4. Talk to Customer Care";
    cout << "\n0. Exit IVR";

    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 0)
    {
        cout << "\nExiting IVR System...\n";
        return;
    }

    else if (choice == 1)
        cout << "\nYou selected Billing Support.\n";

    else if (choice == 2)
        cout << "\nYou selected Technical Support.\n";

    else if (choice == 3)
        cout << "\nYou selected Product Information.\n";

    else if (choice == 4)
        cout << "\nConnecting to Customer Care.\n";

    else
        cout << "\nInvalid choice!\n";

    // Recursive function call
    IVR();
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== CUSTOMER SERVICE MANAGEMENT =====";

        cout << "\n1. Add Normal Request";
        cout << "\n2. Add Urgent Request";
        cout << "\n3. Process Normal Request";
        cout << "\n4. Process Urgent Request";
        cout << "\n5. Display Resolved History";
        cout << "\n6. Open IVR System";
        cout << "\n0. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
            addNormalRequest();

        else if (choice == 2)
            addUrgentRequest();

        else if (choice == 3)
            processNormalRequest();

        else if (choice == 4)
            processUrgentRequest();

        else if (choice == 5)
            displayHistory();

        else if (choice == 6)
            IVR();

        else if (choice == 0)
            cout << "\nExiting program...\n";

        else
            cout << "\nInvalid choice!\n";

    } while (choice != 0);

    return 0;
}
