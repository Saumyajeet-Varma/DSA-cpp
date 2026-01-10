#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int i = 0, ans = 1, n = arr.size();
        priority_queue<int> pq;
        while (pq.size() != k)
        {
            if ((i < n && ans < arr[i]) || i >= n)
                pq.push(ans);
            if (i < n && ans == arr[i])
                i++;
            ans++;
        }
        return pq.top();
    }
};