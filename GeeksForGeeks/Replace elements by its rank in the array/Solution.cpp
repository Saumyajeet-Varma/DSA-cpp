#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        vector<pair<int, int>> rank;

        for (int i = 0; i < N; i++)
        {
            rank.push_back({arr[i], i});
        }

        sort(rank.begin(), rank.end());

        int j = 0;
        for (int i = 0; i < N; i++)
        {
            if (i > 0 && rank[i].first != rank[i - 1].first)
                j++;
            arr[rank[i].second] = j + 1;
        }

        return arr;
    }
};