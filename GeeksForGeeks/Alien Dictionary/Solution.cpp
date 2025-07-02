#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto node : adj[i])
            {
                indegree[node]++;
            }
        }

        queue<int> que;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                que.push(i);
        }

        vector<int> topo;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            topo.push_back(node);

            for (auto adjNode : adj[node])
            {
                indegree[adjNode]--;

                if (indegree[adjNode] == 0)
                    que.push(adjNode);
            }
        }

        return topo.size() == V ? topo : vector<int>{};
    }

public:
    string findOrder(vector<string> &words)
    {
        int n = words.size();

        vector<int> letters(26, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto ch : words[i])
            {
                if (letters[ch - 'a'] == 0)
                {
                    letters[ch - 'a'] = 1;
                }
            }
        }

        vector<vector<int>> adj(26);

        for (int i = 0; i < n - 1; i++)
        {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.length(), s2.length());

            bool flag = false;

            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    flag = true;
                    break;
                }
            }

            if (!flag && s1.length() > s2.length())
                return "";
        }

        vector<int> topo = topoSort(26, adj);

        if (topo.empty())
            return "";

        string result = "";

        for (auto it : topo)
        {
            if (letters[it])
                result += char(it + 'a');
        }

        return result;
    }
};