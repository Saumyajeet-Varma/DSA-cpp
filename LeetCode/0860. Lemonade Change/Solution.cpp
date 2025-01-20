#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();

        int five = 0;
        int ten = 0;

        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
            {
                five += 1;
            }
            else if (bills[i] == 10)
            {
                if (five)
                {
                    five -= 1;
                    ten += 1;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (ten && five)
                {
                    five -= 1;
                    ten -= 1;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};