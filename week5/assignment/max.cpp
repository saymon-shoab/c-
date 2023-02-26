#include<iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

int max(int array[], int n)
{
    if (n==1) return array[n-1];
    
    int possible_max = max(array,n-1);
    if (possible_max>array[n-1]){
        return possible_max;
    }else 
    {
        return array[n-1];
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    };
    cout<<max(arr,n);

    return 0;
}