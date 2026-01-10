#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProduct(vector<int> arr, int n)
    {
        long long prod = 1;
        long long maxProd = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (prod == 0)
                prod = 1;
            prod *= arr[i];
            maxProd = max(prod, maxProd);
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (prod == 0)
                prod = 1;
            prod *= arr[i];
            maxProd = max(prod, maxProd);
        }
        return maxProd;
    }
};