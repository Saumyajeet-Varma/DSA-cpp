#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> toposort(int V, vector<vector<int>> adj)
    {
        vector<int> indegree(V, 0);

        for (int node = 0; node < V; node++)
        {
            for (int adjNode : adj[node])
            {
                indegree[adjNode]++;
            }
        }

        queue<int> que;

        for (int node = 0; node < V; node++)
        {
            if (indegree[node] == 0)
            {
                que.push(node);
            }
        }

        vector<int> result;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            result.push_back(node);

            for (int adjNode : adj[node])
            {
                indegree[adjNode]--;

                if (indegree[adjNode] == 0)
                {
                    que.push(adjNode);
                }
            }
        }

        return result.size() == V ? result : vector<int>{};
    }

public:
    string foreignDictionary(vector<string> &words)
    {
        vector<int> letters(26, 0);

        for (string word : words)
        {
            for (char ch : word)
            {
                if (!letters[ch - 'a'])
                {
                    letters[ch - 'a'] = 1;
                }
            }
        }

        int n = words.size();

        vector<vector<int>> adj(26);

        for (int i = 0; i < n - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.length(), word2.length());
            bool flag = false;

            for (int j = 0; j < len; j++)
            {
                if (word1[j] != word2[j])
                {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    flag = true;
                    break;
                }
            }

            if (!flag && word1.length() > word2.length())
            {
                return "";
            }
        }

        vector<int> topo = toposort(26, adj);

        if (topo.empty())
        {
            return "";
        }

        string result = "";

        for (int it : topo)
        {
            if (letters[it])
            {
                result += char(it + 'a');
            }
        }

        return result;
    }
};
