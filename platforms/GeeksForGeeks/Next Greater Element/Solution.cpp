#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> nge(n);
        stack<int> stk;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top() <= arr[i])
            {
                stk.pop();
            }

            if (stk.empty())
                nge[i] = -1;
            else
                nge[i] = stk.top();

            stk.push(arr[i]);
        }

        return nge;
    }
};