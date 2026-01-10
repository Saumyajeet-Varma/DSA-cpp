#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        int q = queries.size();
        vector<int> prefix(n);
        vector<int> result(q);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }
        for (int i = 0; i < q; i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            if (left == 0)
            {
                result[i] = prefix[right];
            }
            else
            {
                result[i] = prefix[right] ^ prefix[left - 1];
            }
        }
        return result;
    }
};