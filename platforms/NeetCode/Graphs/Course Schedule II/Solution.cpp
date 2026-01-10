#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (numCourses == 0)
        {
            return {};
        }

        if (numCourses == 1)
        {
            return {0};
        }

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (vector<int> prerequisite : prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> que;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }

        vector<int> order;

        while (!que.empty())
        {
            int course = que.front();
            que.pop();

            order.push_back(course);

            for (int precourse : adj[course])
            {
                indegree[precourse]--;

                if (indegree[precourse] == 0)
                {
                    que.push(precourse);
                }
            }
        }

        return order.size() == numCourses ? order : vector<int>{};
    }
};
