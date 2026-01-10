#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, value;
        Node *next, *prev;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node *> mpp;

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertNode(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    int get(int key)
    {
        if (mpp.find(key) == mpp.end())
            return -1;
        else
        {
            Node *currNode = mpp[key];
            deleteNode(currNode);
            insertNode(currNode);
            return currNode->value;
        }
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *currNode = mpp[key];
            currNode->value = value;
            deleteNode(currNode);
            insertNode(currNode);
        }
        else
        {
            Node *newNode = new Node(key, value);
            if (mpp.size() == capacity)
            {
                Node *delNode = tail->prev;
                mpp.erase(delNode->key);
                deleteNode(delNode);
                insertNode(newNode);
                mpp[key] = newNode;
                delete delNode;
            }
            else
            {
                insertNode(newNode);
                mpp[key] = newNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */