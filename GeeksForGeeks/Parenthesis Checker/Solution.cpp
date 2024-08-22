#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispar(string x)
    {
        stack<char> myStack;
        for (char c : x)
        {
            switch (c)
            {
            case '(':
                myStack.push(c);
                break;
            case '{':
                myStack.push(c);
                break;
            case '[':
                myStack.push(c);
                break;
            case ')':
                if (myStack.empty() || myStack.top() != '(')
                    return false;
                else
                    myStack.pop();
                break;
            case '}':
                if (myStack.empty() || myStack.top() != '{')
                    return false;
                else
                    myStack.pop();
                break;
            case ']':
                if (myStack.empty() || myStack.top() != '[')
                    return false;
                else
                    myStack.pop();
                break;
            default:;
            }
        }
        return myStack.empty();
    }
};