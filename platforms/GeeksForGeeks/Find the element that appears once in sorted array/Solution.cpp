#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findOnce(int arr[], int n)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }
        for (auto it : freq)
        {
            if (it.second == 1)
                return it.first;
        }
        return -1;
    }
};