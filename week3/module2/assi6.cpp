#include<bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;
 
bool Is_Duplicate(vector<int> &a, int k)
{
    // Finding first occurrence of k
    int l = 0, h = a.size() - 1, first = -1;
    while (l <= h)
    {
        int middle = l + (h - l) / 2;
        if (a[middle] >= k)
        {
            if (a[middle] == k)
                first = middle;
            h = middle - 1;
        }
        else
            l = middle + 1;
    }
    if (first == -1)
        // k not found in the aay
        return false;
    // Finding last occurrence of k
    int last = -1;
    l = 0, h = a.size() - 1;
    while (l <= h)
    {
        int middle = l + (h - l) / 2;
        if (a[middle] > k)
            h = middle - 1;
        else
        {
            if (a[middle] == k)
                last = middle;
            l = middle + 1;
        }
    }
    return (first != last);
}
 
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    if (Is_Duplicate(a, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
 
    return 0;
}

