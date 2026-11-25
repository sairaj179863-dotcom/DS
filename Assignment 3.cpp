
#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    string category;
    float price;
    int quantity;
    string expiry;
};

Product p[100];
int n = 0;

// Add Product
void addProduct()
{
    cout << "\nEnter Product ID: ";
    cin >> p[n].id;

    cout << "Enter Product Name: ";
    cin >> ws;
    getline(cin, p[n].name);

    cout << "Enter Category: ";
    getline(cin, p[n].category);

    cout << "Enter Price: ";
    cin >> p[n].price;

    cout << "Enter Quantity: ";
    cin >> p[n].quantity;

    cout << "Enter Expiry Date (YYYY-MM-DD): ";
    cin >> p[n].expiry;

    n++;

    cout << "\nProduct added successfully!\n";
}

// Display Products
void displayProducts()
{
    if (n == 0)
    {
        cout << "\nNo products available!\n";
        return;
    }

    cout << "\n--- Product Inventory ---\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nProduct ID: " << p[i].id;
        cout << "\nName: " << p[i].name;
        cout << "\nCategory: " << p[i].category;
        cout << "\nPrice: " << p[i].price;
        cout << "\nQuantity: " << p[i].quantity;
        cout << "\nExpiry Date: " << p[i].expiry << "\n";
    }
}

// Search Product
void searchProduct()
{
    int choice;

    cout << "\n1. Search by Product ID";
    cout << "\n2. Search by Product Name";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int id;
        cout << "Enter Product ID: ";
        cin >> id;

        for (int i = 0; i < n; i++)
        {
            if (p[i].id == id)
            {
                cout << "\nProduct Found!";
                cout << "\nName: " << p[i].name;
                cout << "\nPrice: " << p[i].price;
                cout << "\nQuantity: " << p[i].quantity;
                cout << "\nExpiry: " << p[i].expiry << "\n";
                return;
            }
        }
    }

    else if (choice == 2)
    {
        string name;
        cout << "Enter Product Name: ";
        cin >> ws;
        getline(cin, name);

        for (int i = 0; i < n; i++)
        {
            if (p[i].name == name)
            {
                cout << "\nProduct Found!";
                cout << "\nID: " << p[i].id;
                cout << "\nCategory: " << p[i].category;
                cout << "\nPrice: " << p[i].price;
                cout << "\nQuantity: " << p[i].quantity;
                cout << "\nExpiry: " << p[i].expiry << "\n";
                return;
            }
        }
    }

    else
    {
        cout << "\nInvalid choice!\n";
        return;
    }

    cout << "\nProduct not found!\n";
}

// Update Product
void updateProduct()
{
    int id;

    cout << "\nEnter Product ID to update: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (p[i].id == id)
        {
            cout << "Enter New Product Name: ";
            cin >> ws;
            getline(cin, p[i].name);

            cout << "Enter New Category: ";
            getline(cin, p[i].category);

            cout << "Enter New Price: ";
            cin >> p[i].price;

            cout << "Enter New Quantity: ";
            cin >> p[i].quantity;

            cout << "Enter New Expiry Date: ";
            cin >> p[i].expiry;

            cout << "\nProduct updated successfully!\n";
            return;
        }
    }

    cout << "\nProduct not found!\n";
}

// Delete Product
void deleteProduct()
{
    int id;

    cout << "\nEnter Product ID to delete: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (p[i].id == id)
        {
            for (int j = i; j < n - 1; j++)
            {
                p[j] = p[j + 1];
            }

            n--;

            cout << "\nProduct deleted successfully!\n";
            return;
        }
    }

    cout << "\nProduct not found!\n";
}

// Sort Products
void sortProducts()
{
    int choice;

    cout << "\n1. Sort by Price";
    cout << "\n2. Sort by Quantity";
    cout << "\n3. Sort by Expiry Date";
    cout << "\nEnter choice: ";
    cin >> choice;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            bool swapNeeded = false;

            if (choice == 1 && p[j].price > p[j + 1].price)
                swapNeeded = true;

            else if (choice == 2 && p[j].quantity > p[j + 1].quantity)
                swapNeeded = true;

            else if (choice == 3 && p[j].expiry > p[j + 1].expiry)
                swapNeeded = true;

            if (swapNeeded)
            {
                Product temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    cout << "\nProducts sorted successfully!\n";
    displayProducts();
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== GROCERY INVENTORY SYSTEM =====";
        cout << "\n1. Add Product";
        cout << "\n2. Display Products";
        cout << "\n3. Search Product";
        cout << "\n4. Update Product";
        cout << "\n5. Delete Product";
        cout << "\n6. Sort Products";
        cout << "\n0. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
            addProduct();

        else if (choice == 2)
            displayProducts();

        else if (choice == 3)
            searchProduct();

        else if (choice == 4)
            updateProduct();

        else if (choice == 5)
            deleteProduct();

        else if (choice == 6)
            sortProducts();

        else if (choice == 0)
            cout << "\nExiting program...\n";

        else
            cout << "\nInvalid choice!\n";

    } while (choice != 0);

    return 0;
}
