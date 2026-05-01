// 1
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
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
        cout << "\nEnter the roll number of student: ";
        cin >> nim;

        //1
        Node *newNode = new Node();

        //2
        newNode->noMhs = nim;

        //3
        if (START != NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //4
            newNode->next = START;

            //5
            if (START != NULL)
                START->prev = newNode;

            //6
            newNode->prev = NULL;
            
            //7
            START = newNode;
            return;
        }

        //
        //
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim) 
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        //9
        newNode->next = current->next;
        newNode->prev = current;

        //
        if (current->next != NULL)
            current->next->prev = newNode;

        current->next = newNode;    
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be delete: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        //
        while (current != NULL && current->noMhs != rollNo)
               current = current->next;
        
        
    
    }
}
