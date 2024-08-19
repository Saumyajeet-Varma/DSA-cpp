#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<long long, long long> getMinMax(vector<long long int> arr)
    {
        long long max = arr[0];
        long long min = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (max < arr[i])
                max = arr[i];
            if (min > arr[i])
                min = arr[i];
        }
        return {min, max};
    }
};