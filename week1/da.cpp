
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
TIME COMPLEXITY O(1);
MEMORY COMPLEXITY O(1) 
*/
class Array{
private:
    int *arr;
    int cap;
    int sz;
    void Increase_size(){
        cap = cap*2 ;
        int *tmp = new int[cap];
        for (int i = 0; i < sz; i++)
        {
            tmp[i]=arr[i];
        }
        delete [] arr;
        arr = tmp;
        
    }
public:
    Array(){
        arr = new int[1];
        cap = 1;
        sz = 0;
    }
    void Push_back(int x){
        if (cap==sz)
        {
            Increase_size();
        }
        arr[sz]=x;
        sz++;
    }
    void Insert(int pos, int x){
        if (cap==sz)
        {
            Increase_size();
        }
        for (int i = sz-1; i < pos; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[pos]=x;
        sz++;
    }
    void Print(){
        for (int i = 0; i < sz; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    int getSize(){
        return sz;
    }
    int getElement(int idx){
        if (idx>=sz)
        {
            cout<<"Error "<<idx<<" is out of bound!\n";
            return -1;
        }
        return arr[idx];
    }
    void Pop_back(){
        if (sz==0)
        {
            cout<<"Current size: 0\n";
            return;
        }
        sz--;
    }
    void Erase(int pos){
        if (pos>=sz)
        {
            cout<<"Position dose not exist.\n";
            return;
        }
        for (int i = pos+1; i < sz; i--)
        {
            arr[i-1]=arr[i];
        }
        sz--;
    }

};
int main()
{
    Array a;
    a.Push_back(33);
    a.Push_back(22);
    a.Push_back(88);
    a.Push_back(44);
    a.Push_back(11);
    a.Insert(1,4);
    a.Print();
    // cout<<a.getSize()<<"\n";
    // for (int i = 0; i < a.getSize(); i++)
    // {
    //     cout<<a.getElement(i)<<"\n";
    // }
    a.Pop_back();
    a.Print();
    a.Pop_back();
    a.Print();
    a.Erase(1);
    a.Print();
    return 0;
}