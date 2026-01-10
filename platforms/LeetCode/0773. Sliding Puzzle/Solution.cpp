#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        set<string> vis;
        queue<string> que;
        string start = "";
        for (auto row : board)
        {
            for (auto grid : row)
            {
                start += grid + '0';
            }
        }
        que.push(start);
        vis.insert(start);
        int step = 0;
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                string curr = que.front();
                que.pop();
                if (curr == target)
                    return step;
                int zero = curr.find('0');
                for (auto move : dir[zero])
                {
                    string next = curr;
                    swap(next[move], next[zero]);
                    if (!vis.count(next))
                    {
                        vis.insert(next);
                        que.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};