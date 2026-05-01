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
    }
}
