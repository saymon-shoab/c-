// Online C++ compiler to run C++ program online
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
class node{
public:
    int data;
    node * nxt;
};

class LinkedList{
public:
    node * head;
    int sz;
    LinkedList(){
        head = NULL;
        sz=0;
    }
    // create a new node with data = value and nxt = nul
    node* CreateNewNode(int value){
        node *newnode = new node;
        newnode->data= value;
        newnode->nxt = NULL;
        return newnode;
    }
    // Insert new value at head
    void InsertAtHead(int value){
        sz++;
        node *a = CreateNewNode(value);
        if(head == NULL){
            head = a;
            return;
        }
        // if head is not NULL
        a->nxt = head;
        head =a;
    }
    // Prints the linked list
    void Traverse(){
        node* a = head;
        while(a!=NULL){
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }
    // search for a single value
    int SearchDistictValue(int value){
        node* a = head;
        int index = 0;
        while(a!=NULL){
            if(a->data==value){
                return index;
            }
            a = a->nxt;
            index++;
        }
        return -1;
    }
    //search all possible occurance
    void SearchAllValue(int value){
        node* a = head;
        int index = 0;
        while(a!=NULL){
            if(a->data==value){
                cout<<value<<"is found at index"<<index<<"\n";
            }
            a = a->nxt;
            index++;
        }
    }
    // O(n);
    // int getSize(){
    //     int size = 0;
    //     node *a = head;
    //     while (a!=NULL)
    //     {
    //         size++;
    //         a=a->nxt;
    //     }
    //     return size;
    // }
    int getSize(){
        // O(1);
        return sz;
    }
    void InsertAtAnyIndex(int index, int value){
        if (index<0 || index>sz)
        {
            return;
        }
        if (index==0)
        {
            InsertAtHead(value);
            return;
        }
        sz++;
        node *a = head;
        int cur_index = 0;
        while (cur_index!=index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *newnode = CreateNewNode(value);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }
    void DeleteAtHead(){
        if (head==NULL)
        {
            return;
        }
        sz--;
        node *a = head;
        head = a->nxt;
        delete a;
    }
    void InsertAfterValue (int value, int data){
        node *a = head;
        while (a != NULL)
        {
            if(a->data==value){
                break;
            }
            a = a->nxt;
        }
        if (a==NULL)
        {
            cout<<value<<"doesn,t exist in linked-list.\n";
            return;
        }
        sz++;
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        a->nxt=newnode;
    }
    void DeleteAnyIndex(int index){
        if (index<0 || index>sz-1)
        {
            return;
        }
        
        if (index==0)
        {
            DeleteAtHead();
            return;
        }
        sz--;
        node *a = head;
        int cur_index=0;
        while (cur_index != index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }
    // print the reverce order...
    void RevercePrint2(node *a){
        if (a==NULL)
        {
            return;
        }
        RevercePrint2(a->nxt);
        cout<<a->data<<" ";
    }
     void RevercePrint(){
        RevercePrint2(head);
        cout<<"\n";
    }
};

int main() {

    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(5);
    l.InsertAtHead(8);
    l.InsertAtHead(34);
    // l.Traverse();
    // l.InsertAfterValue(10,10);
    l.Traverse();
    l.RevercePrint();
    l.Traverse();
    // cout<<l.getSize()<<"\n";
    return 0;
}
