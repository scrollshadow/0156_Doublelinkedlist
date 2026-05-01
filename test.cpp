#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    string nama;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "Enter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newnode = new Node();

        // Step 2: Assign value to the data field
        newnode->noMhs = nim;

        // Step 3: Insert at beginning if list is empty or nim < first node
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "Duplicate roll numbers not allowed" << endl;
                return;
            }

            newnode->next = START;

            if (START != NULL)
                START->prev = newnode;

            newnode->prev = NULL;
            START = newnode;
            return;
        }

        // Step 4: 
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "Duplicate roll numbers not allowed" << endl;
            return;
        }

        Node *nextnode = current->next;
        newnode->next = nextnode;
        newnode->prev = current;

        if (nextnode != NULL)
            nextnode->prev = newnode;

        current->next = newnode;
    }

    void deleteNode()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            if (current->next != NULL)
                current->next->prev = current->prev;

            if (current->prev != NULL)
                current->prev->next = current->next;
        }

        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *currentnode = START;

        cout << "Records in ascending order of roll number are:" << endl;

        while (currentnode != NULL)
        {
            cout << currentnode->noMhs << " ";
            currentnode = currentnode->next;
        }
        cout << endl;
    }

    void reverse()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *currentnode = START;

        while (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
        }

        cout << "Records in descending order of roll number are:" << endl;

        while (currentnode != NULL)
        {
            cout << currentnode->noMhs << " ";
            currentnode = currentnode->prev;
        }
        cout << endl;
    }

    void search()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number to be searched: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Record not found" << endl;
        }
        else
        {
            cout << "Record found" << endl;
            cout << "Roll number: " << current->noMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "\n1. Add Record";
        cout << "\n2. Delete Record";
        cout << "\n3. Traverse (Ascending)";
        cout << "\n4. Reverse (Descending)";
        cout << "\n5. Search Record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.deleteNode();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.reverse();
            break;
        case '5':
            list.search();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option" << endl;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

    } while (choice != '6');

    return 0;
}