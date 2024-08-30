#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> duplicates(vector<int> arr)
    {
        int n = arr.size();
        if (n == 0 || n == 1)
            return {-1};
        vector<int> result;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                result.push_back(arr[i]);
                int j = i + 2;
                while (arr[j] == arr[i])
                {
                    j++;
                }
                i = j - 1;
            }
        }
        if (result.size() == 0)
            return {-1};
        return result;
    }
};