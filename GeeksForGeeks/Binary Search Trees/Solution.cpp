#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBSTTraversal(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i] <= arr[i - 1])
                return false;
        }
        return true;
    }
};