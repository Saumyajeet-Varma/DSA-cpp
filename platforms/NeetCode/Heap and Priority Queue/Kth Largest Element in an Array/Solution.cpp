#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();

        priority_queue<int> pq;

        for (int num : nums)
        {
            pq.push(num);

            if (pq.size() > n - k + 1)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};
