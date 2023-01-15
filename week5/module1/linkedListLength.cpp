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
};

int main() {
LinkedList l;
cout<<l.getSize()<<"\n";

l.InsertAtHead(10);
cout<<l.getSize()<<"\n";

l.InsertAtHead(5);
cout<<l.getSize()<<"\n";

l.InsertAtHead(8);
cout<<l.getSize()<<"\n";
    return 0;
}
