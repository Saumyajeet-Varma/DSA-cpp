#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void updateVal(int idx, int val, vector<int> &fen)
    {
        int n = fen.size();

        while (idx < n)
        {
            fen[idx] += val;
            idx += (idx & -idx);
        }
    }

    int getVal(int idx, vector<int> &fen)
    {
        int result = 0;

        while (idx > 0)
        {
            result += fen[idx];
            idx -= (idx & -idx);
        }

        return result;
    }

public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();

        long long result = 0;

        vector<int> pos(n, 0);
        vector<int> reIndex(n, 0);
        vector<int> fenSmall(n + 1, 0);
        vector<int> fenBig(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            pos[nums2[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            reIndex[i] = pos[nums1[i]];
        }

        for (int i = 1; i <= n; i++)
        {
            updateVal(i, 1, fenBig);
        }

        for (int i = 0; i < n; i++)
        {
            updateVal(reIndex[i] + 1, -1, fenBig);
            updateVal(reIndex[i] + 1, 1, fenSmall);

            int smaller = getVal(reIndex[i], fenSmall);
            int bigger = getVal(n, fenBig) - getVal(reIndex[i], fenBig);

            result += (long long)smaller * bigger;
        }

        return result;
    }
};