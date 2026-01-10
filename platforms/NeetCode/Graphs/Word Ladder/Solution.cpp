#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
        {
            return 0;
        }

        if (beginWord == endWord)
        {
            return 1;
        }

        queue<pair<string, int>> que;

        que.push({beginWord, 1});
        st.erase(beginWord);

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();

            string word = curr.first;
            int steps = curr.second;

            if (word == endWord)
            {
                return steps;
            }

            for (int i = 0; i < word.length(); i++)
            {
                char ch = word[i];

                for (int c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;

                    if (st.find(word) != st.end())
                    {
                        que.push({word, steps + 1});
                        st.erase(word);
                    }
                }

                word[i] = ch;
            }
        }

        return 0;
    }
};
