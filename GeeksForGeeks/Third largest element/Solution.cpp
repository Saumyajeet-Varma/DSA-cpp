#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdLargest(vector<int> &arr)
    {
        int n = arr.size();

        if (n < 3)
            return -1;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);

            if (pq.size() > 3)
                pq.pop();
        }

        return pq.top();
    }
};