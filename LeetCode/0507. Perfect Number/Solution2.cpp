#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        int sum = 0;
        for (int i = 1; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                sum += i;
                if (i != sqrt(num) && i > 1)
                    sum += num / i;
            }
        }
        return sum == num;
    }
};