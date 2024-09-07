#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int> pq;
        for (auto it : arr)
        {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};