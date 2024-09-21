#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> stk;
    int idx;

    StockSpanner()
    {
        idx = -1;
    }

    int next(int price)
    {
        idx += 1;
        int span;
        while (!stk.empty() && stk.top().first <= price)
        {
            stk.pop();
        }
        span = idx - (stk.empty() ? -1 : stk.top().second);
        stk.push({price, idx});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */