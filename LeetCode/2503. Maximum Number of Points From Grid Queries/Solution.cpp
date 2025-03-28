#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int n = grid.size();
        int m = grid[0].size();
        int q = queries.size();

        vector<int> result(q);
        vector<pair<int, int>> queryIndex(q);
        vector<vector<int>> vis(n, vector<int>(m, -1));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < q; i++)
        {
            queryIndex[i] = {queries[i], i};
        }

        sort(queryIndex.begin(), queryIndex.end());

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        int count = 0;

        for (int i = 0; i < q; i++)
        {
            while (!pq.empty() && pq.top().first < queryIndex[i].first)
            {
                count++;

                auto topp = pq.top();
                pq.pop();

                int x = topp.second.first;
                int y = topp.second.second;

                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if ((nx >= 0 && ny >= 0 && nx < n && ny < m) && vis[nx][ny] == -1)
                    {
                        vis[nx][ny] = 1;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }

            result[queryIndex[i].second] = count;
        }

        return result;
    }
};