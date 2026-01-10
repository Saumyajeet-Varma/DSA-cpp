#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        if (target <= startValue)
            return startValue - target;

        int count = 0;

        while (startValue < target)
        {
            if (target % 2 == 0)
            {
                target /= 2;
                count++;
            }
            else
            {
                target += 1;
                count++;
            }

            if (target == startValue)
                return count;
        }

        return count + (startValue - target);
    }
};