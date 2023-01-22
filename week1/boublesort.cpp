#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
TIME COMPLEXITY O(1);
MEMORY COMPLEXITY O(1) 
*/

int main()
{
   
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // n ta fass;
    // time complexity o(n^2)
    // memory complexity o(n)
    for(int pass=0;pass<n;pass++)
    {
        int last = n-1-pass;
        for(int j=0;j<=last-1;j++)
        {
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
        cout<<"after pass "<<pass<<": ";
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    cout<<"After sorting..: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}