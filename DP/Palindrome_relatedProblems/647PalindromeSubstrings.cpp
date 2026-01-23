// Approach-1 (Simply check all substrings possilbe)
// T.C : O(n^3)
// S.C : O(1)
class Solution
{
public:
    bool check(string &s, int i, int j)
    {
        if (i >= j)
        {
            return true;
        }

        if (s[i] == s[j])
        {
            return check(s, i + 1, j - 1);
        }

        return false;
    }

    int countSubstrings(string s)
    {
        int n = s.length();

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            { // check all possible substrings
                if (check(s, i, j))
                {
                    count++;
                }
            }
        }

        return count;
    }
};

// Approach-2 (Memoize the approach above)
// T.C : O(n^2) - Every subproblem is being computed only once and after that it's being reused
// S.C : O(n^2)
class Solution
{
public:
    int t[1001][1001];
    bool check(string &s, int i, int j)
    {
        if (i >= j)
        {
            return true;
        }

        if (t[i][j] != -1)
        {
            return t[i][j]; // 1 : True, 0 : False
        }

        if (s[i] == s[j])
        {
            return t[i][j] = check(s, i + 1, j - 1);
        }

        return t[i][j] = false;
    }

    int countSubstrings(string s)
    {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            { // check all possible substrings
                if (check(s, i, j))
                {
                    count++;
                }
            }
        }

        return count;
    }
};

// Approach-3 (Dynamic Programming - Bottom Up)
// T.C : O(n^2)
// S.C : O(n^2)
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();

        int count = 0;

        vector<vector<int>> t(n, vector<int>(n, 0));

        for (int L = 1; L <= n; L++)
        {
            for (int i = 0; i + L - 1 < n; i++)
            {
                int j = i + L - 1;

                if (i == j)
                    t[i][i] = true;
                else if (i + 1 == j)
                    t[i][j] = (s[i] == s[j]);
                else
                    t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);

                if (t[i][j])
                    count++;
            }
        }

        return count;
    }
};