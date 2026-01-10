#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtrack(unordered_map<char, int> &freq, int &result)
    {
        for (auto &it : freq)
        {
            if (it.second > 0)
            {
                result++;

                it.second--;
                backtrack(freq, result);
                it.second++;
            }
        }
    }

public:
    int numTilePossibilities(string tiles)
    {
        int n = tiles.length();

        if (n == 1)
            return 1;

        unordered_map<char, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[tiles[i]]++;
        }

        int result = 0;

        backtrack(freq, result);

        return result;
    }
};