#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string numStr1 = to_string(num);
        string numStr2 = numStr1;
        unordered_map<char, int> mpp;
        int n = numStr1.size();
        for (int i = 0; i < n; i++)
        {
            mpp[numStr1[i]] = i;
        }
        sort(numStr2.rbegin(), numStr2.rend());
        int i = 0;
        while (i < n)
        {
            if (numStr2[i] == numStr1[i])
                i++;
            else
            {
                swap(numStr1[mpp[numStr2[i]]], numStr1[i]);
                return stoi(numStr1);
            }
        }
        return stoi(numStr1);
    }
};