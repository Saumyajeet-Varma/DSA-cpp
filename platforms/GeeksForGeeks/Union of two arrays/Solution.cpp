#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int doUnion(vector<int> arr1, vector<int> arr2)
    {
        map<int, int> mp;
        for (int i = 0; i < arr1.size(); i++)
        {
            mp[arr1[i]]++;
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            mp[arr2[i]]++;
        }
        return mp.size();
    }
};