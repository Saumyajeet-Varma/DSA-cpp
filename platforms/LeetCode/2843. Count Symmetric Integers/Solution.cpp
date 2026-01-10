#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSymmetric(int num)
    {
        string str = to_string(num);

        int n = str.length();

        if (n % 2 == 1)
            return false;

        int half = n / 2;
        int firstHalf = 0;
        int secondHalf = 0;

        for (int i = 0; i < n; i++)
        {
            if (i < half)
                firstHalf += str[i] - '0';
            else
                secondHalf += str[i] - '0';
        }

        return firstHalf == secondHalf;
    }

public:
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;

        for (int num = low; num <= high; num++)
        {
            if (isSymmetric(num))
                count++;
        }

        return count;
    }
};