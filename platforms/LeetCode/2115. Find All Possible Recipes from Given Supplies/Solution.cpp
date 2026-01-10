#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        int n = recipes.size();

        vector<string> result;
        vector<int> deg(n, 0);
        unordered_map<string, vector<int>> adj;
        unordered_set<string> supp(supplies.begin(), supplies.end());
        queue<int> que;

        for (int i = 0; i < n; i++)
        {
            for (string &s : ingredients[i])
            {
                if (!supp.count(s))
                {
                    adj[s].push_back(i);
                    deg[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 0)
                que.push(i);
        }

        while (!que.empty())
        {
            int i = que.front();
            que.pop();

            auto s = recipes[i];
            result.push_back(s);

            for (auto j : adj[s])
            {
                deg[j]--;
                if (deg[j] == 0)
                    que.push(j);
            }
        }

        return result;
    }
};