#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();

        vector<int> candyArr(n);

        candyArr[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                candyArr[i] = candyArr[i - 1] + 1;
            else
                candyArr[i] = 1;
        }

        int candy = max(1, candyArr[n - 1]);

        int curr = 1;
        int right = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                curr = right + 1;
            else
                curr = 1;

            right = curr;
            candy += max(candyArr[i], curr);
        }

        return candy;
    }
};