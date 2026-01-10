#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }

        long long count = 0;

        while (pq.top() < k)
        {
            long long num1 = pq.top();
            pq.pop();

            long long num2 = pq.top();
            pq.pop();

            long long num = 2 * min(num1, num2) + max(num1, num2);

            pq.push(num);

            count++;
        }

        return count;
    }
};