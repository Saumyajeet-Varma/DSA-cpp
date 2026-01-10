#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool operationalMax(int &x, int &y)
    {
        if (x < y)
        {
            x = y;
            return true;
        }

        return false;
    }

    bool check(vector<pair<int, int>> arr)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int prev = -1;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int l = arr[i].first;
            int r = arr[i].second;

            if (l >= prev)
            {
                count++;
                prev = r;
            }
            else
            {
                operationalMax(prev, r);
            }
        }

        return count >= 3;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        int size = rectangles.size();

        vector<pair<int, int>> rect1;
        vector<pair<int, int>> rect2;

        for (auto rectangle : rectangles)
        {
            rect1.push_back({rectangle[0], rectangle[2]});
            rect2.push_back({rectangle[1], rectangle[3]});
        }

        return check(rect1) || check(rect2);
    }
};