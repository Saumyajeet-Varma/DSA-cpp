#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return 0;

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
                return steps;

            for (int i = 0; i < word.length(); i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {
                        que.push({word, steps + 1});
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};