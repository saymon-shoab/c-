#include<iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<int>quick_sort(vector<int>&a)
{
    if (a.size()<=1)
    {
        return a;
    }
    int pivot = a.size()-1;
    vector<int>l,r;
    for (int i = 0; i < a.size(); i++)
    {
        if (i==pivot)
        {
            continue;
        }
        if (a[i]>=a[pivot])
        {
            r.push_back(a[i]);
        }else
        {
            l.push_back(a[i]);
        }
    }
    vector<int>sorted_r=quick_sort(r);
    vector<int>sorted_l=quick_sort(l);
    vector<int>sorted_a;
    for (int i = 0; i < sorted_r.size(); i++)
    {
        sorted_a.push_back(sorted_r[i]);
    }
    sorted_a.push_back(a[pivot]);
    for (int i = 0; i < sorted_l.size(); i++)
    {
        sorted_a.push_back(sorted_l[i]);
    }
    // sorted_a.push_back(a[pivot]);
    return sorted_a;
}
int main(){
    vector<int>a= {5,3,4,2,6,2};
    vector<int>sorted_a= quick_sort(a);
    for (int i = 0; i < sorted_a.size(); i++)
    {
        cout<<sorted_a[i]<<" ";
    }
    
    return 0;
}