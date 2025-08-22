class Solution
{
public:
    int solve(int index, int open, string &s, vector<map<int, int>> &dp)
    {
        if (index >= s.length())
        {
            return open == 0 ? 1 : 0;
        }
        if (dp[index].count(open))
            return dp[index][open];

        int ans = 0;
        if (s[index] == '*')
        {
            ans |= solve(index + 1, open + 1, s, dp); // treat '*' as '('
            ans |= solve(index + 1, open, s, dp);     // treat '*' as empty
            if (open > 0)
                ans |= solve(index + 1, open - 1, s, dp); // treat '*' as ')'
        }
        else if (s[index] == '(')
        {
            ans |= solve(index + 1, open + 1, s, dp);
        }
        else
        { // ')'
            if (open > 0)
                ans |= solve(index + 1, open - 1, s, dp);
        }

        return dp[index][open] = ans;
    }

    bool checkValidString(string s)
    {
        int n = s.length();
        vector<map<int, int>> dp(n);
        return solve(0, 0, s, dp);
    }
};

// bottom up

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.size();
        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
        // State Definition :
        // t[i][j] = if the string from index i to n-1 is valid or not having j open brackets
        t[n][0] = true;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int open = 0; open <= n; open++)
            {
                bool isValid = false;

                if (s[i] == '*')
                {
                    isValid |= t[i + 1][open + 1]; // Treating * as ( --> solve(i+1, open+1)
                    if (open > 0)
                    {
                        isValid |= t[i + 1][open - 1]; // Treating * as ) --> solve(i+1, open-1)
                    }
                    isValid |= t[i + 1][open]; // Treating * as empty --> solve(i+1, open)
                }
                else
                {
                    if (s[i] == '(')
                    {
                        isValid |= t[i + 1][open + 1]; // solve(i+1, open+1)
                    }
                    else if (open > 0)
                    {
                        isValid |= t[i + 1][open - 1]; // solve(i+1, open=-1)
                    }
                }
                t[i][open] = isValid;
            }
        }

        return t[0][0];
    }
};

// using stack

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> openSt;
        stack<int> asterisksSt;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                openSt.push(i);
            }
            else if (ch == '*')
            {
                asterisksSt.push(i);
            }
            else
            {
                if (!openSt.empty())
                {
                    openSt.pop();
                }
                else if (!asterisksSt.empty())
                {
                    asterisksSt.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        // This post processing will be required for cases like - "*(())(*"
        while (!openSt.empty() && !asterisksSt.empty())
        {
            if (openSt.top() > asterisksSt.top())
            {
                return false;
            }
            openSt.pop();
            asterisksSt.pop();
        }

        return openSt.empty();
    }
};

// greedy approach

class Solution
{
public:
    bool checkValidString(string s)
    {
        int open = 0;
        int close = 0;
        int n = s.length();

        // Left to Right - Check Open Brackets
        for (int i = 0; i < n; i++)
        {

            if (s[i] == '(' || s[i] == '*')
            {
                open++;
            }
            else
            {
                open--;
            }

            if (open < 0)
            {
                return false;
            }
        }

        // Right to Left - Check CLose Brackets
        for (int i = n - 1; i >= 0; i--)
        {

            if (s[i] == ')' || s[i] == '*')
            {
                close++;
            }
            else
            {
                close--;
            }

            if (close < 0)
            {
                return false;
            }
        }

        return true;
    }
};
