#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalJumps(int X, int Y, int N, int arr[])
    {
        int jumps = 0;

        int i = 0;
        while (i < N)
        {
            if (arr[i] <= X)
            {
                jumps++;
                i++;
            }
            else
            {
                jumps++;
                arr[i] -= (X - Y);
            }
        }

        return jumps;
    }
};