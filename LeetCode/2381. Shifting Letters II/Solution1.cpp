#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.length();
        vector<int> shiftArr(n + 1, 0);

        for (auto shift : shifts)
        {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            int shiftVal = direction == 1 ? 1 : -1;

            shiftArr[start] += shiftVal;
            shiftArr[end + 1] -= shiftVal;
        }

        for (int i = 1; i < n; i++)
        {
            shiftArr[i] += shiftArr[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            int finalShift = shiftArr[i] % 26;
            if (finalShift < 0)
                finalShift += 26;
            s[i] = 'a' + (s[i] - 'a' + finalShift) % 26;
        }

        return s;
    }
};