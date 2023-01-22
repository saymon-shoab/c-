// question no 8
#include <bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
 
vector<int> even_generator(vector<int> vector_a)
{
    vector<int> en;
    for (int i = 0; i < vector_a.size(); i++)
        if (vector_a[i] % 2 == 0)
            en.push_back(vector_a[i]);
    return en;
}
 
int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    vector<int> en = even_generator(array);
    for (int i = 0; i < en.size(); i++)
        cout << en[i] << " ";
    return 0;
}