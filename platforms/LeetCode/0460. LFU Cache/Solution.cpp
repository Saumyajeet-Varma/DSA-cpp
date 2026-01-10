#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
public:
    class Node
    {
    public:
        int key, val, count;
        Node *next, *prev;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            this->count = 1;
            next = nullptr;
            prev = nullptr;
        }
    };

    class List
    {
    public:
        Node *head;
        Node *tail;
        List()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int size;
    int minCount;
    unordered_map<int, Node *> keyNodeMap;
    unordered_map<int, List *> countListMap;

    LFUCache(int capacity)
    {
        size = capacity;
    }

    void insertNode(Node *head, Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key)
    {
        if (keyNodeMap.find(key) == keyNodeMap.end())
            return -1;
        else
        {
            Node *resNode = keyNodeMap[key];
            deleteNode(resNode);
            if (resNode->count == minCount && countListMap[resNode->count]->head->next == countListMap[resNode->count]->tail)
                minCount++;
            resNode->count++;
            if (countListMap.find(resNode->count) == countListMap.end())
            {
                List *newList = new List;
                countListMap[resNode->count] = newList;
            }
            insertNode(countListMap[resNode->count]->head, resNode);
            return resNode->val;
        }
    }

    void put(int key, int value)
    {
        if (keyNodeMap.find(key) != keyNodeMap.end())
        {
            keyNodeMap[key]->val = value;
            get(key);
        }
        else
        {
            if (keyNodeMap.size() == size)
            {
                Node *delNode = countListMap[minCount]->tail->prev;
                keyNodeMap.erase(delNode->key);
                deleteNode(delNode);
            }
            Node *newNode = new Node(key, value);
            keyNodeMap[key] = newNode;
            if (countListMap.find(newNode->count) == countListMap.end())
            {
                List *newList = new List;
                countListMap[newNode->count] = newList;
            }
            insertNode(countListMap[newNode->count]->head, newNode);
            minCount = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */