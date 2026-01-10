#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        queue<string> que;
        vector<string> happyStrings;
        vector<char> letters = {'a', 'b', 'c'};

        que.push("a");
        que.push("b");
        que.push("c");

        while (!que.empty())
        {
            string str = que.front();
            que.pop();

            if (str.size() == n)
            {
                happyStrings.push_back(str);
                continue;
            }

            for (char ch : letters)
            {
                if (str.back() != ch)
                {
                    que.push(str + ch);
                }
            }
        }

        return k > happyStrings.size() ? "" : happyStrings[k - 1];
    }
};