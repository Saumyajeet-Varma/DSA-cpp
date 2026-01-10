#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    void backtrack(string s, int idx, vector<string> &partition, vector<vector<string>> &result)
    {
        int n = s.length();

        if (idx == n)
        {
            result.push_back(partition);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            if (isPalindrome(s, idx, i))
            {
                partition.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, partition, result);
                partition.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> partition;

        backtrack(s, 0, partition, result);

        return result;
    }
};
