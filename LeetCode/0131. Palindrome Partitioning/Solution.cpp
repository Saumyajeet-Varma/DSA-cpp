#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string str, int start, int end)
    {
        while (start <= end)
        {
            if (str[start] != str[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void backtrack(string str, int idx, vector<string> &partitions, vector<vector<string>> &result)
    {
        if (idx == str.length())
        {
            result.push_back(partitions);
            return;
        }

        for (int i = idx; i < str.length(); i++)
        {
            if (isPalindrome(str, idx, i))
            {
                partitions.push_back(str.substr(idx, i - idx + 1));
                backtrack(str, i + 1, partitions, result);
                partitions.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> partitions;

        backtrack(s, 0, partitions, result);

        return result;
    }
};