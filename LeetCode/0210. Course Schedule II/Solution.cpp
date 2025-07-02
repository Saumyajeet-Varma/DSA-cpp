#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (numCourses == 0)
            return {};

        if (numCourses == 1)
            return {0};

        vector<vector<int>> precourses(numCourses);

        for (auto prerequisite : prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];

            precourses[v].push_back(u);
        }

        vector<int> numPrecourses(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            for (auto course : precourses[i])
            {
                numPrecourses[course]++;
            }
        }

        queue<int> que;

        for (int i = 0; i < numCourses; i++)
        {
            if (numPrecourses[i] == 0)
                que.push(i);
        }

        vector<int> order;

        while (!que.empty())
        {
            int course = que.front();
            que.pop();

            order.push_back(course);

            for (auto precourse : precourses[course])
            {
                numPrecourses[precourse]--;

                if (numPrecourses[precourse] == 0)
                    que.push(precourse);
            }
        }

        return order.size() == numCourses ? order : vector<int>{};
    }
};