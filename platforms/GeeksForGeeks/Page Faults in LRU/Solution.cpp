#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        int pageFault = 0;
        deque<int> memory;

        for (int i = 0; i < N; i++)
        {
            auto it = find(memory.begin(), memory.end(), pages[i]);

            if (it == memory.end())
            {
                pageFault++;

                if (memory.size() == C)
                    memory.pop_front();
            }
            else
            {
                memory.erase(it);
            }

            memory.push_back(pages[i]);
        }

        return pageFault;
    }
};