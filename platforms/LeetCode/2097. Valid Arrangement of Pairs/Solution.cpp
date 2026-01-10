#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<int, int> degree;
        for (auto &pair : pairs)
        {
            adjacencyList[pair[0]].push_back(pair[1]);
            degree[pair[0]]++;
            degree[pair[1]]--;
        }
        int startNode = pairs[0][0];
        for (auto &it : degree)
        {
            if (it.second == 1)
            {
                startNode = it.first;
                break;
            }
        }
        vector<int> path;
        stack<int> nodeStack;
        nodeStack.push(startNode);
        while (!nodeStack.empty())
        {
            auto &neighbors = adjacencyList[nodeStack.top()];
            if (neighbors.empty())
            {
                path.push_back(nodeStack.top());
                nodeStack.pop();
            }
            else
            {
                int nextNode = neighbors.back();
                nodeStack.push(nextNode);
                neighbors.pop_back();
            }
        }
        vector<vector<int>> arrangement;
        int pathSize = path.size();
        arrangement.reserve(pathSize - 1);
        for (int i = pathSize - 1; i > 0; --i)
        {
            arrangement.push_back({path[i], path[i - 1]});
        }
        return arrangement;
    }
};