#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countWave(int num)
    {
        string numStr = to_string(num);

        int n = numStr.length();

        int count = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if ((numStr[i] > numStr[i - 1] && numStr[i] > numStr[i + 1]) || (numStr[i] < numStr[i - 1] && numStr[i] < numStr[i + 1]))
            {
                count++;
            }
        }

        return count;
    }

public:
    int totalWaviness(int num1, int num2)
    {
        int count = 0;

        for (int i = num1; i <= num2; i++)
        {
            count += countWave(i);
        }

        return count;
    }
};