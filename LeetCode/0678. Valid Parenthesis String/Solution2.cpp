#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceeded
class Solution
{
private:
    bool recursiveFn(string s, int index, int count)
    {
        if (count < 0)
            return false;
        if (index == s.length())
            return count == 0;
        if (s[index] == '(')
            return recursiveFn(s, index + 1, count + 1);
        if (s[index] == ')')
            return recursiveFn(s, index + 1, count - 1);

        return (recursiveFn(s, index + 1, count + 1) || recursiveFn(s, index + 1, count - 1) || recursiveFn(s, index + 1, count));
    }

public:
    bool checkValidString(string s)
    {
        return recursiveFn(s, 0, 0);
    }
};