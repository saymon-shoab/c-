#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class node{
public:
    int data;
    node* nxt;
    node* prv;
};

class DoubleLinkedList{
public:
    node *head;

    DoubleLinkedList(){
        head = NULL;
    }
    node* CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    };
    void InsertAtHead(int data){
        node *newnode = CreateNewNode(data);
        if (head==NULL)
        {
            head = newnode;
            return;
        }
        newnode->nxt = head;
        head->prv = newnode;
        head = newnode;
        
    }
    void Insert(int index, int data){
        if (index==0)
        {
            InsertAtHead(data);
            return;
        };
        node *a = head;
        int cur_index=0;
        while (cur_index!= index-1)
        {
            if(a==NULL)
               break;
            
            a = a->nxt;
            cur_index++;
        }
        if (a==NULL)
        {
            cout<<"cna,t insert\n";
            return;
        }
        node* newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        node* b= a->nxt;
        if (b!=NULL)
        {
            b->prv=newnode;
        }
        a->nxt = newnode;
        newnode->prv=a;
        
    }
    void Traverse(){
        node *a = head;
        while (a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }
};

int main(){
   DoubleLinkedList dl;
   dl.InsertAtHead(30);
   dl.InsertAtHead(20);
   dl.InsertAtHead(10);
   dl.Traverse();
   return 0;
}