#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> result(n, 0);

        int count = boxes[0] == '1' ? 1 : 0;

        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] + count;
            count += boxes[i] == '1' ? 1 : 0;
        }

        count = boxes[n - 1] == '1' ? 1 : 0;

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] + count;
            count += boxes[i] == '1' ? 1 : 0;
        }

        for (int i = 0; i < n; i++)
        {
            result[i] = left[i] + right[i];
        }

        return result;
    }
};