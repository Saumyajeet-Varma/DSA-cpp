#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        int i = 0;
        int j = 0;
        int count = 0;
        int maxCount = 0;

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        while (i < n)
        {
            if (arr[i] <= dep[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};