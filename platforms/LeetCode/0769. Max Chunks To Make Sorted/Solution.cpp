#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int maxx = arr[0];
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            maxx = max(maxx, arr[i]);
            if (maxx == i)
                count++;
        }
        return count;
    }
};