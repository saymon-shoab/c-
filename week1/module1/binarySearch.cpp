#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
TIME COMPLEXITY =
MEMORY COMPLEXITY = o(n);
*/

class Array{
private:
    int *arr;
    int cap;
    int sz;
    void Increase_size(){
        cap = cap*2;
        int *tmp = new int[cap];
        for(int i=0;i<sz;i++){
            tmp[i]==arr[i];
        }
        delete [] arr;
        arr = tmp;
    };
public:
    Array(){
        arr= new int[1];
        cap = 1;
        sz = 0;
    }
    void Push_back(int x){
        if(cap==sz){
            Increase_size();
        }
        arr[sz]=x;
        sz++;
    }
    void Insert(int pos, int x){
        
    }
    void Print(){
        for(int i=0;i<sz;i++){
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
            cout<<"ERROR "<<idx<<"is out of bound!\n";
            return -1;
        }
        return arr[idx];
    }
};

int main()
{
    Array a;
    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Push_back(40);
    a.Push_back(50);
     a.Print();
    cout<<a.getSize()<<"\n";
    for(int i=0;i<a.getSize();i++){
        cout<<a.getElement(i)<<"\n";
    }
    return 0;
}
