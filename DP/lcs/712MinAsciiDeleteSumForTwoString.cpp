class Solution
{
public:
    int solve(int i, int j, string s1, string s2, string &ans, string &temp)
    {
        if (i >= s1.length() || j >= s2.length())
        {
            if (temp.length() > ans.length())
                ans = temp;
            else if (temp.length() == ans.length() && temp > ans)
            {
                ans = temp;
            }

            return 0;
        }

        if (s1[i] == s2[j])
        {
            temp += s1[i];
            int v = 1 + solve(i + 1, j + 1, s1, s2, ans, temp);
            temp.pop_back();
            return v;
        }

        int a1 = solve(i, j + 1, s1, s2, ans, temp);
        int a2 = solve(i + 1, j, s1, s2, ans, temp);

        return max(a1, a2);
    }
    int minimumDeleteSum(string s1, string s2)
    {

        string ans = "", temp = "";
        solve(0, 0, s1, s2, ans, temp);

        int totalAsciiSum = 0;
        for (auto c : s1)
            totalAsciiSum += (c);
        for (auto c : s2)
            totalAsciiSum += (c);

        int ansAsciiSum = 0;
        for (auto c : ans)
            ansAsciiSum += (c);

        return totalAsciiSum - 2 * ansAsciiSum;
    }
}; // recurssion approach TLE--- this is my appraoch

// recursion +dp

class Solution
{
public:
    int m, n;

    int t[1001][1001];

    int solve(string &s1, string &s2, int i, int j)
    {
        if (i >= m && j >= n)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        if (i >= m)
        {
            return t[i][j] = s2[j] + solve(s1, s2, i, j + 1);
        }
        else if (j >= n)
        {
            return t[i][j] = s1[i] + solve(s1, s2, i + 1, j);
        }

        if (s1[i] == s2[j])
            return t[i][j] = solve(s1, s2, i + 1, j + 1);

        int take_s1_i = s1[i] + solve(s1, s2, i + 1, j);
        int take_s2_j = s2[j] + solve(s1, s2, i, j + 1);

        return t[i][j] = min(take_s1_i, take_s2_j);
    }

    int minimumDeleteSum(string s1, string s2)
    {
        m = s1.length();
        n = s2.length();

        memset(t, -1, sizeof(t));

        return solve(s1, s2, 0, 0);
    }
};