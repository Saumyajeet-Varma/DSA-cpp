#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1 == sentence2)
            return true;

        vector<string> s1, s2;
        stringstream ss1(sentence1), ss2(sentence2);
        string word;

        while (ss1 >> word)
        {
            s1.push_back(word);
        }

        while (ss2 >> word)
        {
            s2.push_back(word);
        }

        int s1StartIndex = 0, s1EndIndex = s1.size() - 1;
        int s2StartIndex = 0, s2EndIndex = s2.size() - 1;

        while (s1StartIndex <= s1EndIndex && s2StartIndex <= s2EndIndex && s1[s1StartIndex] == s2[s2StartIndex])
        {
            s1StartIndex++;
            s2StartIndex++;
        }

        while (s1StartIndex <= s1EndIndex && s2StartIndex <= s2EndIndex && s1[s1EndIndex] == s2[s2EndIndex])
        {
            s1EndIndex--;
            s2EndIndex--;
        }

        return s1EndIndex < s2StartIndex || s2EndIndex < s1StartIndex;
    }
};