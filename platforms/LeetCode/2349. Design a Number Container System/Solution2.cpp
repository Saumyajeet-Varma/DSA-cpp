#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
public:
    unordered_map<int, int> indexMap;
    unordered_map<int, set<int>> setMap;

    NumberContainers() {}

    void change(int index, int number)
    {
        if (indexMap.find(index) != indexMap.end())
        {
            int num = indexMap[index];
            setMap[num].erase(index);
        }

        indexMap[index] = number;
        setMap[number].insert(index);
    }

    int find(int number)
    {
        if (setMap[number].size() == 0)
            return -1;

        return *setMap[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */