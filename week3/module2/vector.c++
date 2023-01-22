#include<bits/stdc++.h>
#include<vector>
#include<iostream>
// question no 4...

using namespace std;

bool Is_Subset(vector<int> &vector1, vector<int> &vector2)
{
    sort(vector1.begin(),vector1.end());
    sort(vector2.begin(),vector2.end());
    int i=0,j=0;
    while (i<vector1.size() && j < vector2.size())
    {
        if (vector1[i]<vector2[i])
        {
            return false;
        }else if (vector1[i]==vector2[i])
        {
            i++;
        }else{
            j++;
        }
    }
    return (i == vector1.size());
}

int main(){
    int n1,n2;
    cin>>n1;
    vector<int>vector1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin>>vector1[i];
    }
    cin>>n2;
    vector<int>vector2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin>>vector2[i];
    }
    if (Is_Subset(vector1,vector2))
    {
        cout<<"YES";
    }else
    {
        cout<<"NO";
    }
    return 0;
}