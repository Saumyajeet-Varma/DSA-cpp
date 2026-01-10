#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        priority_queue<int> pq;

        int n = arr.size();

        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        for (int i = 0; i < k; i++)
        {
            int topp = pq.top();
            pq.pop();

            result.push_back(topp);
        }

        return result;
    }
};