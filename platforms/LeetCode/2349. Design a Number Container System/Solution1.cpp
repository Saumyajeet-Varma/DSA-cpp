#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
public:
    unordered_map<int, int> indexMap;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> pqMap;

    NumberContainers() {}

    void change(int index, int number)
    {
        if (indexMap.count(index) && indexMap[index] == number)
            return;

        indexMap[index] = number;
        pqMap[number].push(index);
    }

    int find(int number)
    {
        if (!pqMap.count(number))
            return -1;

        auto &pq = pqMap[number];

        while (!pq.empty() && indexMap[pq.top()] != number)
        {
            pq.pop();
        }

        return pq.empty() ? -1 : pq.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */