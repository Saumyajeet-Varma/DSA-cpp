#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
};