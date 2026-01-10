#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers
{
private:
    vector<int> stream;

public:
    ProductOfNumbers()
    {
        stream.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            stream.clear();
            stream.push_back(1);
        }
        else
        {
            stream.push_back(stream.back() * num);
        }
    }

    int getProduct(int k)
    {
        if (k >= stream.size())
        {
            return 0;
        }

        return stream.back() / stream[stream.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */