#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node *nxt;
    node *prv;
};

template <class T>
class DoublyLinkedList
{
public:
    node<T> *head;
    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }
    node<T> *CreateNewNode(int data)
    {
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }
    // insert a data at the head of the linked list O(1);
    void InsertAtHead(T data)
    {
        sz++;
        node<T> *newnode = CreateNewNode(data);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        node<T> *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }

    // delete at head ..
    void DeleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        node<T> *a = head;
        node<T> *b = head->nxt;
        delete a;
        if (b != NULL)
        {
            b->prv == NULL;
        }
        head = b;
        sz--;
    }

    // return the size of linked list O(1);
    int getSize()
    {
        return sz;
    }
};

// stack using doubly linked list..
template <class T>
class Stack
{
public:
    DoublyLinkedList<T> dl;

    Stack()
    {
    }
    T top()
    {
        if (dl.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            T a;
            return a;
        }
        return dl.head->data;
    }
    void push(T val)
    {
        dl.InsertAtHead(val);
    }
    void pop()
    {
        if (dl.getSize() == 0)
        {
            cout << "stack is empty\n";
            return;
        }
        dl.DeleteAtHead();
    }
    int getSize()
    {
        return dl.getSize();
    }
};

int main()
{
    // reverse a stack using another stack;
    Stack<int> a;
    a.push(4);
    a.push(6);
    a.push(5);
    a.push(9);

    Stack<int> tmp;
    while (a.getSize() > 0)
    {
        tmp.push(a.top());
        a.pop();
    }
    swap(a, tmp);
    while (a.getSize() > 0)
    {
        cout << a.top() << "\n";
        a.pop();
    }
    return 0;
}