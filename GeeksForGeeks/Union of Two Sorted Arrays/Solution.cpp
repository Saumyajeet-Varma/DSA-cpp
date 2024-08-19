#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> unionArr;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr1[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            mp[arr2[i]]++;
        }
        for (auto it : mp)
        {
            unionArr.push_back(it.first);
        }
        return unionArr;
    }
};