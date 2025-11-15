#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> result;
        backtrack(S, result, 0);
        return result;
    }

private:
    bool backtrack(const string &s, vector<int> &result, int ind)
    {
        if (ind == (int)s.size())
        {
            return result.size() > 2;
        }

        long long num = 0;
        for (int i = ind; i < (int)s.size(); ++i)
        {
            num = num * 10 + (s[i] - '0');
            // If number exceeds 32-bit signed int, stop extending this number
            if (num > INT_MAX)
                break;

            if (result.size() < 2 ||
                (long long)result[result.size() - 1] + result[result.size() - 2] == num)
            {
                result.push_back((int)num);
                if (backtrack(s, result, i + 1))
                    return true;
                result.pop_back();
            }

            // leading zero — don't allow numbers with leading zeros (except "0" itself)
            if (i == ind && s[i] == '0')
                return false;
        }

        return false;
    }
};
