#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s == goal)
            return true;
        int n = s.length();
        string rotatedStr = s;
        for (int i = 0; i < n; i++)
        {
            char letter = rotatedStr[0];
            rotatedStr = rotatedStr.substr(1);
            rotatedStr = rotatedStr + letter;
            if (rotatedStr == goal)
                return true;
            if (rotatedStr == s)
                break;
        }
        return false;
    }
};