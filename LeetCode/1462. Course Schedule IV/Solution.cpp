#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<bool> result;
        unordered_map<int, unordered_set<int>> reachable;

        for (auto &prerequisite : prerequisites)
        {
            reachable[prerequisite[1]].insert(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            for (int j = 0; j < numCourses; j++)
            {
                if (reachable[j].count(i))
                    reachable[j].insert(reachable[i].begin(), reachable[i].end());
            }
        }

        for (auto &query : queries)
        {
            result.push_back(reachable[query[1]].count(query[0]) > 0);
        }

        return result;
    }
};