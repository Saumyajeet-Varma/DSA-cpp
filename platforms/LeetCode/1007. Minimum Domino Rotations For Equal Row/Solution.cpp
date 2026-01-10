#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getRotation(vector<int> &tops, vector<int> &bottoms, int target)
    {
        int n = tops.size();

        int rotateTop = 0;
        int rotateBottom = 0;

        for (int i = 0; i < n; i++)
        {
            if (tops[i] != target && bottoms[i] != target)
                return INT_MAX;

            if (tops[i] != target)
                rotateTop++;

            if (bottoms[i] != target)
                rotateBottom++;
        }

        return min(rotateTop, rotateBottom);
    }

public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int result = getRotation(tops, bottoms, tops[0]);

        if (tops[0] != bottoms[0])
            result = min(result, getRotation(tops, bottoms, bottoms[0]));

        return result == INT_MAX ? -1 : result;
    }
};