#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> preCourses(numCourses);

        for (auto prerequisite : prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];

            preCourses[v].push_back(u);
        }

        vector<int> numPreCourses(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            for (auto course : preCourses[i])
            {
                numPreCourses[course]++;
            }
        }

        queue<int> que;

        for (int i = 0; i < numCourses; i++)
        {
            if (numPreCourses[i] == 0)
                que.push(i);
        }

        vector<int> topo;

        while (!que.empty())
        {
            int course = que.front();
            que.pop();

            topo.push_back(course);

            for (auto preCourse : preCourses[course])
            {
                numPreCourses[preCourse]--;

                if (numPreCourses[preCourse] == 0)
                    que.push(preCourse);
            }
        }

        return topo.size() == numCourses;
    }
};