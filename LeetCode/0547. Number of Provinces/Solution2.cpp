#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(int i, int n, vector<vector<int>> &adjMat, vector<int> &vis, queue<int> &que)
    {
        que.push(i);
        vis[i] = 1;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            for (int nbr = 0; nbr < n; nbr++)
            {
                if (adjMat[node][nbr] && !vis[nbr])
                {
                    que.push(nbr);
                    vis[nbr] = 1;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();

        if (n == 1)
            return 1;

        int count = 0;
        vector<int> vis(n, 0);
        queue<int> que;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bfs(i, n, isConnected, vis, que);
                count++;
            }
        }

        return count;
    }
};