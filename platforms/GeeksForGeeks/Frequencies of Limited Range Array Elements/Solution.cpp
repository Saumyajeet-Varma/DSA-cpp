#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        map<int, int> mpp;
        for (int i = 0; i < N; i++)
        {
            mpp[arr[i]]++;
        }
        for (int i = 0; i < N; i++)
        {
            if (mpp.find(i + 1) != mpp.end())
            {
                arr[i] = mpp[i + 1];
            }
            else
            {
                arr[i] = 0;
            }
        }
    }
};