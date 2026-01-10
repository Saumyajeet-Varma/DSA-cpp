#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool backtrack(int index, int n, vector<int> &result, vector<bool> &usedNums)
    {
        int resSize = result.size();

        if (index == resSize)
            return true;

        if (result[index])
            return backtrack(index + 1, n, result, usedNums);

        for (int i = n; i >= 1; i--)
        {
            if (!usedNums[i])
            {
                if (i == 1)
                {
                    result[index] = i;
                    usedNums[i] = true;
                }
                else
                {
                    int nextIndex = index + i;

                    if (nextIndex < resSize && result[nextIndex] == 0)
                    {
                        result[index] = i;
                        result[nextIndex] = i;
                        usedNums[i] = true;
                    }
                    else
                    {
                        continue;
                    }
                }

                if (backtrack(index + 1, n, result, usedNums))
                    return true;

                result[index] = 0;

                if (i != 1)
                {
                    int nextIndex = index + i;
                    result[nextIndex] = 0;
                }

                usedNums[i] = false;
            }
        }

        return false;
    }

public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> result(2 * n - 1, 0);
        vector<bool> usedNums(n + 1, false);

        backtrack(0, n, result, usedNums);

        return result;
    }
};