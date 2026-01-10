#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

        parent[node] = findParent(parent[node]);

        return parent[node];
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();

        unordered_map<string, int> mailNode;

        DisjointSet ds(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];

                if (mailNode.find(mail) == mailNode.end())
                    mailNode[mail] = i;
                else
                    ds.unionBySize(i, mailNode[mail]);
            }
        }

        vector<vector<string>> merged(n);

        for (auto it : mailNode)
        {
            string mail = it.first;
            int node = it.second;

            int parent = ds.findParent(node);

            merged[parent].push_back(mail);
        }

        vector<vector<string>> result;

        for (int i = 0; i < n; i++)
        {
            if (merged[i].empty())
                continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto mail : merged[i])
            {
                temp.push_back(mail);
            }

            result.push_back(temp);
        }

        return result;
    }
};