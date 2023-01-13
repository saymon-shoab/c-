// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class node{
public:
    int data;
    node * nxt;
};

class LinkedList{
public:
    node * head;
    LinkedList(){
        head = NULL;
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
};

int main() {
LinkedList l;
l.Traverse();
l.InsertAtHead(10);
l.Traverse();
l.InsertAtHead(30);
l.Traverse();
l.InsertAtHead(20);
l.Traverse();
l.InsertAtHead(30);
l.Traverse();
cout<<"10 is found at"<<l.SearchDistictValue(10)<<"\n";
cout<<"5 is found at"<<l.SearchDistictValue(5)<<"\n";
cout<<"30 is found at"<<l.SearchDistictValue(30)<<"\n";
l.SearchAllValue(30);
    return 0;
}
