#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        unordered_set<string> palindromes;

        int half = (n + 1) / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half) - 1;

        for (int num = start; num <= end; num++)
        {
            string left = to_string(num);
            string right = left.substr(0, n % 2 == 0 ? half : half - 1);

            reverse(right.begin(), right.end());

            string palindrome = left + right;
            long long palindromeNum = stoll(palindrome);

            if (palindromeNum % k != 0)
                continue;

            sort(palindrome.begin(), palindrome.end());
            palindromes.insert(palindrome);
        }

        vector<long long> fact(11, 1);

        for (int i = 1; i <= 10; i++)
        {
            fact[i] = fact[i - 1] * i;
        }

        long long count = 0;

        for (auto &palindrome : palindromes)
        {
            vector<int> digits(10, 0);

            for (auto &ch : palindrome)
            {
                digits[ch - '0']++;
            }

            int len = palindrome.length();
            int zeroes = digits[0];
            int nonZeroes = len - zeroes;

            long long permutation = nonZeroes * fact[len - 1];

            for (auto &digit : digits)
            {
                permutation /= fact[digit];
            }

            count += permutation;
        }

        return count;
    }
};