#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int targetSum = skill[0] + skill[n - 1];
        long long chemistry = 0;
        for (int i = 0; i < n / 2; i++)
        {
            int currSum = skill[i] + skill[n - i - 1];
            if (currSum != targetSum)
                return -1;
            chemistry += (long long)skill[i] * skill[n - i - 1];
        }
        return chemistry;
    }
};