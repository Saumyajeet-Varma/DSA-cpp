#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long atLeastK(string &word, int k)
    {
        int n = word.size();

        long long result = 0;
        int consonants = 0;

        unordered_map<char, int> vowelMap;

        int l = 0;
        int r = 0;

        while (r < n)
        {
            if (isVowel(word[r]))
                vowelMap[word[r]]++;
            else
                consonants++;

            while (vowelMap.size() == 5 && consonants >= k)
            {
                result += n - r;

                if (isVowel(word[l]))
                {
                    vowelMap[word[l]]--;

                    if (vowelMap[word[l]] == 0)
                        vowelMap.erase(word[l]);
                }
                else
                {
                    consonants--;
                }

                l++;
            }

            r++;
        }

        return result;
    }

public:
    long long countOfSubstrings(string word, int k)
    {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};