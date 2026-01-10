#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string oddEven(int n)
    {
        if ((n & 1) == 0)
            return "even";
        else
            return "odd";
    }
};