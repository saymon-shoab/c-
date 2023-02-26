#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;



class node
{
public:
    int data;
    node * nxt;
    node * prv;
};

class DoublyLinkedList
{
public:
    node *head;
    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    //Creates a new node with the given data and returns it O(1)
    node * CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    //Inserts a node with given data at head O(1)
    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }

    //Inserts the given data at the given index O(n)
    void Insert(int index, int data)
    {
        if(index > sz)
        {
            return;
        }
        if(index==0)
        {
            InsertAtHead(data);
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index!= index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        // a = cur_index - 1
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        newnode->prv = a;
        node *b = a->nxt;
        b->prv = newnode;
        a->nxt = newnode;
        sz++;
    }

    //Deletes the given index O(n)
    void Delete(int index)
    {
        if(index >= sz)
        {
            cout<<index<<" doesn't exist.\n";
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->prv;
        node *c = a->nxt;
        if(b!=NULL)
        {
            b->nxt = c;
        }
        if(c!= NULL)
        {
            c->prv = b;
        }
        delete a;
        if(index==0)
        {
            head = c;
        }
        sz--;
    }
    // delete gero function...
    void deleteZero(){
        node *current = head;
        node *prev = NULL;
        while (current!=NULL)
        {
            if (current->data == 0)
            {
                if (prev==NULL)
                {
                    head = current->nxt;
                }else
                {
                    prev->nxt = current->nxt;
                }
                node *temp = current; 
                current = current->nxt;
                delete temp;
            }else {
                prev = current;
                current = current->nxt;
            }
            
        }
        
    }
    //Prints the linked list O(n)
    void Traverse()
    {
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    // Returns the size of linked list O(1)
    int getSize()
    {
        return sz;
    }

    //Reverse the doubly linked list O(n)
    void Reverse()
    {
        if(head==NULL)
        {
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != sz-1)
        {
            a = a->nxt;
            cur_index++;
        }
        // last index is in a

        node *b = head;
        while(b!= NULL)
        {
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
    }
};


int main()
{
    DoublyLinkedList dl;
    dl.InsertAtHead(10);
    dl.InsertAtHead(0);
    dl.InsertAtHead(5);
    dl.InsertAtHead(0);
    dl.InsertAtHead(0);
    dl.InsertAtHead(1);
    dl.InsertAtHead(0);
    dl.Traverse();
    dl.Insert(2,100);

    dl.Traverse();

    dl.Reverse();
    dl.deleteZero();
    dl.Traverse();


    return 0;
}