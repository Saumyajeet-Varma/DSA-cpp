#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        vector<int> ans;
        for (int i = 0; i < queries; i++)
        {
            int count = 0;
            for (int j = indices[i]; j < n; j++)
            {
                if (arr[indices[i]] < arr[j])
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};