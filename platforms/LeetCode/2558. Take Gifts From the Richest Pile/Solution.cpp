#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq;
        long long ans = 0;
        int n = gifts.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(gifts[i]);
            ans += gifts[i];
        }
        while (k)
        {
            int topp = pq.top();
            pq.pop();
            ans -= (topp - sqrt(topp));
            pq.push(sqrt(topp));
            k--;
        }
        return ans;
    }
};