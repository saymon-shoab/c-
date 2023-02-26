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
};

int main()
{
    DoublyLinkedList<char> dl;
    dl.InsertAtHead('f');
    dl.InsertAtHead('j');
    dl.InsertAtHead('l');
    dl.InsertAtHead('r');

    dl.DeleteAtHead();
    dl.DeleteAtHead();

    Stack<double> st;
    st.push(3.5);
    st.push(1.6);
    st.push(7.8);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    return 0;
}