#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        vector<string> result;
        sort(folder.begin(), folder.end());
        unordered_map<string, int> mpp;
        for (auto s : folder)
        {
            int n = s.size();
            string temp = "";
            bool flag = 0;
            for (int i = 0; i < n; i++)
            {
                temp.push_back(s[i]);
                if (i == n - 1 && mpp[temp])
                {
                    flag = 1;
                    break;
                }
                else if (mpp[temp] && s[i + 1] == '/')
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                mpp[temp]++;
                result.push_back(temp);
            }
        }
        return result;
    }
};