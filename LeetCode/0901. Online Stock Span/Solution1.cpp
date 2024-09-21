#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    vector<int> arr;

    StockSpanner()
    {
        arr = {};
    }

    int next(int price)
    {
        arr.push_back(price);
        int count = 1;
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] <= price)
                count++;
            else
                break;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */