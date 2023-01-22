#include<bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;
 
class node
{
public:
    int data;
    node *nxt;
};
 
class LinkedList
{
public:
    int size;
    node *head;
    LinkedList()
    {
        head = NULL;
        size = 0;
    }
    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }
    void InsertAtHead(int value)
    {

        node *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            size = 1;
            return;
        }
        a->nxt = head;
        head = a;
        size++;
    }
    void Traverse()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->nxt;
        }
        cout << "\n";
    }
    int SearchDistinctValue(int value)
    {
        node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return index;
            }
            temp = temp->nxt;
            index++;
        }
        return -1;
    }
 
    // Search all possible occurrence
    void SearchAllValue(int value)
    {
        node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << value << " is found at index " << index << endl;
            }
            temp = temp->nxt;
            index++;
        }
    }
 
    int getSize()
    {
        return size;
    }
 
    int getValue(int index)
    {
        if (index >= size)
            return -1;
 
        node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->nxt;
        }
        return temp->data;
    }
 
    void printReverse(node *temp)
    {
        if (temp == NULL)
            return;
        printReverse(temp->nxt);
        cout << temp->data << " ";
    }
 
    void printReverse()
    {
        printReverse(head);
        cout << endl;
    }
 
    void swapFirst()
    {
        if (size < 2)
            return;
 
        node *temp = head->nxt;
        head->nxt = temp->nxt;
        temp->nxt = head;
        head = temp;
    }
};
 
int main()
{

    LinkedList l;
    cout << l.getSize() << "\n";
    l.InsertAtHead(5);
    cout << l.getSize() << "\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout << l.getSize() << "\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);
 
    cout << l.getValue(2) << "\n";
 
    cout << l.getValue(6) << "\n";
 
    l.printReverse();
    l.Traverse();
    l.swapFirst();
    l.Traverse();
    l.printReverse();
    return 0;
}