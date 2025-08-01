#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";

        while (columnNumber)
        {
            columnNumber--;

            char ch = 'A' + columnNumber % 26;
            result = ch + result;

            columnNumber /= 26;
        }

        return result;
    }
};