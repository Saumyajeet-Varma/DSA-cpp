#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit)
    {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

class Solution
{
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit)
    {
        int n = id.size();

        vector<Job> jobs;

        for (int i = 0; i < n; i++)
        {
            jobs.push_back(Job(id[i], deadline[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end(), [](Job val1, Job val2)
             { return val1.profit > val2.profit; });

        int totalProfit = 0;
        int count = 0;
        int maxDeadline = 0;

        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        }

        vector<int> daysArr(maxDeadline + 1, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = jobs[i].deadline; j >= 1; j--)
            {
                if (daysArr[j] == -1)
                {
                    count++;
                    daysArr[j] = jobs[i].id;
                    totalProfit += jobs[i].profit;

                    break;
                }
            }
        }

        return {count, totalProfit};
    }
};