#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int rabbits = 0;

        unordered_map<int, int> mpp;

        for (int answer : answers)
        {
            mpp[answer]++;
        }

        for (auto &it : mpp)
        {
            rabbits += ceil((double)it.second / (it.first + 1)) * (it.first + 1);
        }

        return rabbits;
    }
};