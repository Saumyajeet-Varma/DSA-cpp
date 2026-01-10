#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2)
    {
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int maxsum = 0, arr1sum = 0, arr2sum = 0;
        while (i >= 0 && j >= 0)
        {
            if (arr1[i] > arr2[j])
            {
                arr1sum += arr1[i];
                i--;
            }
            else if (arr1[i] < arr2[j])
            {
                arr2sum += arr2[j];
                j--;
            }
            else
            {
                maxsum += max(arr1sum + arr1[i], arr2sum + arr2[j]);
                i--;
                j--;
                arr1sum = 0;
                arr2sum = 0;
            }
        }
        while (i >= 0)
        {
            arr1sum += arr1[i];
            i--;
        }
        while (j >= 0)
        {
            arr2sum += arr2[j];
            j--;
        }
        maxsum += max(arr1sum, arr2sum);
        return maxsum;
    }
};