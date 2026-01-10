#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        string result;
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch]++;
        }
        priority_queue<pair<char, int>> pq;
        for (char ch = 'z'; ch >= 'a'; ch--)
        {
            if (freq[ch] > 0)
                pq.push({ch, freq[ch]});
        }
        while (!pq.empty())
        {
            auto top1 = pq.top();
            pq.pop();
            int addLimit = min(top1.second, repeatLimit);
            result.append(addLimit, top1.first);
            top1.second -= addLimit;
            if (top1.second > 0)
            {
                if (pq.empty())
                    break;
                auto top2 = pq.top();
                pq.pop();
                result += top2.first;
                top2.second--;
                if (top2.second > 0)
                    pq.push(top2);
                pq.push(top1);
            }
        }
        return result;
    }
};