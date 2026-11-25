
#include <iostream>
#include <string>
using namespace std;

struct Customer
{
    int token;
    string name;
    string category;
};

// Normal Customer Queue
Customer normalQueue[100];
int front = 0, rear = -1;

// Priority Customer Queue
Customer priorityQueue[100];
int pFront = 0, pRear = -1;

// Stack for Served Customers
Customer history[100];
int top = -1;

int tokenNumber = 1;

// Generate Token
void generateToken()
{
    int choice;
    Customer c;

    cout << "\nEnter Customer Name: ";
    cin >> ws;
    getline(cin, c.name);

    cout << "\n1. Normal Customer";
    cout << "\n2. Senior Citizen";
    cout << "\n3. Differently-Abled Customer";

    cout << "\nEnter category: ";
    cin >> choice;

    c.token = tokenNumber++;

    if (choice == 1)
    {
        if (rear == 99)
        {
            cout << "\nNormal queue is full!\n";
            return;
        }

        normalQueue[++rear] = c;

        cout << "\nNormal Token Generated: " << c.token;
    }

    else if (choice == 2 || choice == 3)
    {
        if (pRear == 99)
        {
            cout << "\nPriority queue is full!\n";
            return;
        }

        priorityQueue[++pRear] = c;

        cout << "\nPriority Token Generated: " << c.token;
    }

    else
    {
        tokenNumber--;
        cout << "\nInvalid category!\n";
    }
}

// Serve Customer
void serveCustomer()
{
    Customer c;

    // Priority customers are served first
    if (pFront <= pRear)
    {
        c = priorityQueue[pFront];

        pFront++;

        if (pFront > pRear)
        {
            pFront = 0;
            pRear = -1;
        }

        cout << "\nServing Priority Customer";
    }

    // Normal customers follow FIFO
    else if (front <= rear)
    {
        c = normalQueue[front];

        for (int i = front; i < rear; i++)
        {
            normalQueue[i] = normalQueue[i + 1];
        }

        rear--;

        if (rear < front)
        {
            front = 0;
            rear = -1;
        }

        cout << "\nServing Normal Customer";
    }

    else
    {
        cout << "\nNo customers waiting!\n";
        return;
    }

    cout << "\nToken Number: " << c.token;
    cout << "\nCustomer Name: " << c.name;

    // Push served customer into Stack
    if (top < 99)
    {
        history[++top] = c;
        cout << "\nCustomer served successfully!\n";
    }
    else
    {
        cout << "\nHistory stack is full!\n";
    }
}

// Display Served History
void displayHistory()
{
    if (top == -1)
    {
        cout << "\nNo served customers!\n";
        return;
    }

    cout << "\n--- Served Customer History ---\n";

    for (int i = top; i >= 0; i--)
    {
        cout << "\nToken Number: " << history[i].token;
        cout << "\nCustomer Name: " << history[i].name << "\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== BANK TOKEN MANAGEMENT =====";
        cout << "\n1. Generate Token";
        cout << "\n2. Serve Customer";
        cout << "\n3. Display Served History";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            generateToken();

        else if (choice == 2)
            serveCustomer();

        else if (choice == 3)
            displayHistory();

        else if (choice == 0)
            cout << "\nExiting system...\n";

        else
            cout << "\nInvalid choice!\n";

    } while (choice != 0);

    return 0;
}
