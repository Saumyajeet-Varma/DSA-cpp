#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            int topp = pq.top();
            ans += topp;
            if (topp == 1)
            {
                ans += (k - i - 1);
                break;
            }
            pq.pop();
            pq.push((topp + 2) / 3);
        }
        return ans;
    }
};