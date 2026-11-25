
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

    Product* next;
};

// Hash Table with 10 indexes
Product* hashTable[10] = {NULL};

// Hash Function
int hashFunction(int id)
{
    return id % 10;
}

// Search Product
Product* searchProduct(int id)
{
    int index = hashFunction(id);

    Product* temp = hashTable[index];

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

// Add New Product
void addProduct()
{
    Product* newProduct = new Product;

    cout << "\nEnter Product ID: ";
    cin >> newProduct->id;

    if (searchProduct(newProduct->id) != NULL)
    {
        cout << "\nProduct ID already exists!\n";
        delete newProduct;
        return;
    }

    cout << "Enter Product Name: ";
    cin >> ws;
    getline(cin, newProduct->name);

    cout << "Enter Category: ";
    getline(cin, newProduct->category);

    cout << "Enter Price: ";
    cin >> newProduct->price;

    cout << "Enter Quantity: ";
    cin >> newProduct->quantity;

    int index = hashFunction(newProduct->id);

    // Insert at beginning of linked list
    newProduct->next = hashTable[index];
    hashTable[index] = newProduct;

    cout << "\nProduct added successfully!\n";
}

// Search and Display Product
void displayProduct()
{
    int id;

    cout << "\nEnter Product ID: ";
    cin >> id;

    Product* temp = searchProduct(id);

    if (temp == NULL)
    {
        cout << "\nProduct not found!\n";
    }
    else
    {
        cout << "\nProduct Found!";
        cout << "\nProduct ID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nCategory: " << temp->category;
        cout << "\nPrice: " << temp->price;
        cout << "\nQuantity: " << temp->quantity << "\n";
    }
}

// Update Product
void updateProduct()
{
    int id;

    cout << "\nEnter Product ID to update: ";
    cin >> id;

    Product* temp = searchProduct(id);

    if (temp == NULL)
    {
        cout << "\nProduct not found!\n";
        return;
    }

    cout << "Enter New Product Name: ";
    cin >> ws;
    getline(cin, temp->name);

    cout << "Enter New Category: ";
    getline(cin, temp->category);

    cout << "Enter New Price: ";
    cin >> temp->price;

    cout << "Enter New Quantity: ";
    cin >> temp->quantity;

    cout << "\nProduct updated successfully!\n";
}

// Remove Product
void removeProduct()
{
    int id;

    cout << "\nEnter Product ID to remove: ";
    cin >> id;

    int index = hashFunction(id);

    Product* temp = hashTable[index];
    Product* previous = NULL;

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

            cout << "\nProduct removed successfully!\n";
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "\nProduct not found!\n";
}

// Display All Products
void displayAllProducts()
{
    bool found = false;

    cout << "\n--- All Available Products ---\n";

    for (int i = 0; i < 10; i++)
    {
        Product* temp = hashTable[i];

        while (temp != NULL)
        {
            found = true;

            cout << "\nProduct ID: " << temp->id;
            cout << "\nName: " << temp->name;
            cout << "\nCategory: " << temp->category;
            cout << "\nPrice: " << temp->price;
            cout << "\nQuantity: " << temp->quantity << "\n";

            temp = temp->next;
        }
    }

    if (found == false)
    {
        cout << "\nNo products available!\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== E-COMMERCE PRODUCT SYSTEM =====";
        cout << "\n1. Add Product";
        cout << "\n2. Display All Products";
        cout << "\n3. Search Product";
        cout << "\n4. Update Product";
        cout << "\n5. Remove Product";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            addProduct();

        else if (choice == 2)
            displayAllProducts();

        else if (choice == 3)
            displayProduct();

        else if (choice == 4)
            updateProduct();

        else if (choice == 5)
            removeProduct();

        else if (choice == 0)
            cout << "\nExiting system...\n";

        else
            cout << "\nInvalid choice!\n";

    } while (choice != 0);

    // Free allocated memory
    for (int i = 0; i < 10; i++)
    {
        Product* temp = hashTable[i];

        while (temp != NULL)
        {
            Product* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    return 0;
}
