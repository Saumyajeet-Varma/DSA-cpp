#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        unordered_map<string, int> obs;
        for (auto it : obstacles)
        {
            string key = to_string(it[0]) + "+" + to_string(it[1]);
            obs[key]++;
        }
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int currdir = 1;
        int x = 0, y = 0;
        int dist = 0;
        int n = commands.size();
        for (int i = 0; i < n; i++)
        {
            if (commands[i] == -2)
            {
                if (currdir == 0)
                    currdir = 3;
                else
                    currdir--;
            }
            else if (commands[i] == -1)
            {
                if (currdir == 3)
                    currdir = 0;
                else
                    currdir++;
            }
            else
            {
                for (int j = 1; j <= commands[i]; j++)
                {
                    int newX = x + dir[currdir][0];
                    int newY = y + dir[currdir][1];
                    string key = to_string(newX) + "+" + to_string(newY);
                    if (obs.find(key) != obs.end())
                    {
                        break;
                    }
                    x = newX, y = newY;
                    dist = max(dist, x * x + y * y);
                }
            }
        }
        return dist;
    }
};