#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();

        int candy = 1;
        int i = 1;

        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                candy += 1;
                i++;
                continue;
            }

            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak++;
                candy += peak;
                i++;
            }

            int valley = 1;
            while (i < n && ratings[i] < ratings[i - 1])
            {
                candy += valley;
                valley++;
                i++;
            }

            if (valley > peak)
                candy += valley - peak;
        }

        return candy;
    }
};