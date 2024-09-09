#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        int n = arr.size();
        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }
        for (int i = k; i < n; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};