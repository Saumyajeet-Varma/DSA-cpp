#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool validPartition(string numStr, int target, int index, int currSum)
    {
        int n = numStr.size();

        if (index == n)
            return currSum == target;

        int sum = 0;

        for (int i = index; i < n; i++)
        {
            sum = sum * 10 + (numStr[i] - '0');

            if (sum + currSum > target)
                break;

            if (validPartition(numStr, target, i + 1, currSum + sum))
                return true;
        }

        return false;
    }

public:
    int punishmentNumber(int n)
    {
        int sum = 0;

        for (int i = 1; i <= n; i++)
        {
            int sq = i * i;
            string sqStr = to_string(sq);

            if (validPartition(sqStr, i, 0, 0))
                sum += sq;
        }

        return sum;
    }
};