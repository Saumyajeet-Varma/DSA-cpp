#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        if (k == 1)
            return 0;

        int n = weights.size();

        long long maxx = weights[0] + weights[n - 1];
        long long minn = weights[0] + weights[n - 1];

        vector<int> vec;

        for (int i = 1; i < n; i++)
        {
            vec.push_back(weights[i] + weights[i - 1]);
        }

        sort(vec.begin(), vec.end());

        minn += accumulate(vec.begin(), vec.begin() + k - 1, minn);
        maxx += accumulate(vec.end() - k + 1, vec.end(), maxx);

        return maxx - minn;
    }
};