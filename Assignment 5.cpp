
#include <iostream>
#include <string>
using namespace std;

struct Order
{
    int id;
    string name;
    string item;
};

// Normal Queue
Order normalQueue[100];
int front = 0, rear = -1;

// VIP Queue
Order vipQueue[100];
int vipFront = 0, vipRear = -1;

// Stack for Cancelled Orders
Order cancelled[100];
int top = -1;

// Add Normal Order
void addNormalOrder()
{
    if (rear == 99)
    {
        cout << "\nNormal queue is full!\n";
        return;
    }

    rear++;

    cout << "\nEnter Order ID: ";
    cin >> normalQueue[rear].id;

    cout << "Enter Customer Name: ";
    cin >> ws;
    getline(cin, normalQueue[rear].name);

    cout << "Enter Food Item: ";
    getline(cin, normalQueue[rear].item);

    cout << "\nOrder added successfully!\n";
}

// Add VIP Order
void addVIPOrder()
{
    if (vipRear == 99)
    {
        cout << "\nVIP queue is full!\n";
        return;
    }

    vipRear++;

    cout << "\nEnter Order ID: ";
    cin >> vipQueue[vipRear].id;

    cout << "Enter Customer Name: ";
    cin >> ws;
    getline(cin, vipQueue[vipRear].name);

    cout << "Enter Food Item: ";
    getline(cin, vipQueue[vipRear].item);

    cout << "\nVIP order added successfully!\n";
}

// Process Order
void processOrder()
{
    Order temp;

    // VIP orders get priority
    if (vipFront <= vipRear)
    {
        temp = vipQueue[vipFront];

        cout << "\nProcessing VIP Order";
        vipFront++;

        if (vipFront > vipRear)
        {
            vipFront = 0;
            vipRear = -1;
        }
    }

    // Normal Queue
    else if (front <= rear)
    {
        temp = normalQueue[front];

        cout << "\nProcessing Normal Order";

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
    }

    else
    {
        cout << "\nNo orders available!\n";
        return;
    }

    cout << "\nOrder ID: " << temp.id;
    cout << "\nCustomer: " << temp.name;
    cout << "\nFood Item: " << temp.item;
    cout << "\nOrder processed successfully!\n";
}

// Cancel Order and Push into Stack
void cancelOrder()
{
    int id;
    cout << "\nEnter Order ID to cancel: ";
    cin >> id;

    // Search VIP Queue
    for (int i = vipFront; i <= vipRear; i++)
    {
        if (vipQueue[i].id == id)
        {
            if (top == 99)
            {
                cout << "\nCancellation history is full!\n";
                return;
            }

            cancelled[++top] = vipQueue[i];

            for (int j = i; j < vipRear; j++)
            {
                vipQueue[j] = vipQueue[j + 1];
            }

            vipRear--;

            cout << "\nVIP order cancelled successfully!\n";
            return;
        }
    }

    // Search Normal Queue
    for (int i = front; i <= rear; i++)
    {
        if (normalQueue[i].id == id)
        {
            if (top == 99)
            {
                cout << "\nCancellation history is full!\n";
                return;
            }

            cancelled[++top] = normalQueue[i];

            for (int j = i; j < rear; j++)
            {
                normalQueue[j] = normalQueue[j + 1];
            }

            rear--;

            cout << "\nOrder cancelled successfully!\n";
            return;
        }
    }

    cout << "\nOrder not found!\n";
}

// Display Cancelled Orders
void displayCancelled()
{
    if (top == -1)
    {
        cout << "\nNo cancelled orders!\n";
        return;
    }

    cout << "\n--- Cancelled Order History ---\n";

    for (int i = top; i >= 0; i--)
    {
        cout << "\nOrder ID: " << cancelled[i].id;
        cout << "\nCustomer: " << cancelled[i].name;
        cout << "\nFood Item: " << cancelled[i].item << "\n";
    }
}

// Recursive Menu Navigation
void menu()
{
    int choice;

    cout << "\n===== RESTAURANT ORDER SYSTEM =====";
    cout << "\n1. Add Normal Order";
    cout << "\n2. Add VIP Order";
    cout << "\n3. Process Order";
    cout << "\n4. Cancel Order";
    cout << "\n5. Display Cancelled Orders";
    cout << "\n0. Exit";

    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        addNormalOrder();

    else if (choice == 2)
        addVIPOrder();

    else if (choice == 3)
        processOrder();

    else if (choice == 4)
        cancelOrder();

    else if (choice == 5)
        displayCancelled();

    else if (choice == 0)
    {
        cout << "\nExiting system...\n";
        return;
    }

    else
        cout << "\nInvalid choice!\n";

    // Recursive call
    menu();
}

int main()
{
    menu();
    return 0;
}
