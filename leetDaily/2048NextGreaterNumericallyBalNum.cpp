class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        unordered_map<int, int> mp;

        for (int i = n + 1; i <= 1224444; i++)
        {
            // cout<<i<<endl;
            string num = to_string(i);

            for (auto &x : num)
            {
                mp[x - '0']++;
            }

            bool check = true;
            for (auto &x : mp)
            {
                if (x.first != x.second)
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                return stoi(num);
            }

            mp.clear();
        }

        return 0;
    }
};

// another approach : using backtracking

// Approach-3 (Bakctracking)
// T.C : O(9^d), d = number of digits of n
// S.C : O(1)
class Solution
{
public:
    vector<int> digitCount{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int backtrack(int n, int curr, int count)
    {
        if (count == 0)
        {
            for (int digit = 1; digit <= 9; digit++)
            {
                if (digitCount[digit] != 0 && digitCount[digit] != digit)
                {
                    return 0;
                }
            }

            return curr > n ? curr : 0;
        }

        int result = 0;

        for (int digit = 1; digit <= 9; digit++)
        {
            if (digitCount[digit] > 0 && digitCount[digit] <= count)
            {
                digitCount[digit]--;
                result = backtrack(n, curr * 10 + digit, count - 1);
                digitCount[digit]++;
            }

            if (result != 0)
            {
                break;
            }
        }

        return result;
    }

    int nextBeautifulNumber(int n)
    {
        int numDigits = to_string(n).length();

        int result = backtrack(n, 0, numDigits);
        if (result == 0)
        {
            result = backtrack(n, 0, numDigits + 1);
        }

        return result;
    }
};