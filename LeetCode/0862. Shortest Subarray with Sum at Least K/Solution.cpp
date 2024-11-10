#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        int n = nums.size();
        long long minLen = INT_MAX;
        long long sum = 0;
        for (long long i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum >= k)
                minLen = min(minLen, i + 1);
            while (!pq.empty() && sum - pq.top().first >= k)
            {
                minLen = min(minLen, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};