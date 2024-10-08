#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < size; i++)
        {
            mp[a[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second > size / 2)
            {
                return it.first;
            }
        }
        return -1;
    }
};