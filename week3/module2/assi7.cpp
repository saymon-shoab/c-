// question no 7
#include<bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;
 
int mxin()
{
    int n, x, y;
    cin >> n;
    vector<int> vector_x(n);
    for (int i = 0; i < n; i++)
        cin >> vector_x[i];
    cin >> x;
    cin >> y;
    vector_x.erase(vector_x.begin() + x - 1, vector_x.begin() + y);
    for (int i = 0; i < vector_x.size(); i++)
        cout << vector_x[i] << " ";
    return 0;
}