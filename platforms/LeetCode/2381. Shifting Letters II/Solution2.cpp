#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceed
class Solution
{
private:
    void shiftCharacter(string &s, int start, int end, int direction)
    {
        for (int i = start; i <= end; i++)
        {
            if (direction == 1)
            {
                int currPos = s[i] - 'a';
                int newPos = (currPos + 1) % 26;
                s[i] = 'a' + newPos;
            }
            else
            {
                int currPos = s[i] - 'a';
                int newPos = (currPos + 25) % 26;
                s[i] = 'a' + newPos;
            }
        }
    }

public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = shifts.size();
        for (int i = 0; i < n; i++)
        {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            shiftCharacter(s, start, end, direction);
        }
        return s;
    }
};