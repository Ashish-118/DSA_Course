class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {

        s.erase(remove(s.begin(), s.end(), '-'), s.end());
        int rem = s.length() % k;

        transform(s.begin(), s.end(), s.begin(), ::toupper);

        string code = "";

        for (int i = 0; i < rem; i++)
        {
            code += s[i];
        }
        if (!code.empty())
            code += '-';

        int count = 0;

        for (int i = rem; i < s.length(); i++)
        {
            count++;
            if (count > k)
            {
                count = 1;
                code += '-';
            }

            code += s[i];
        }

        if (code.length() > 1 && code.back() == '-')
            code.erase(code.length() - 1);

        return code;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

/// optimal approach

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        int count = 0;
        int n = s.length();
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '-')
            {
                ans.push_back(toupper(s[i]));
                count++;
                if (count == k)
                {
                    ans.push_back('-');
                    count = 0;
                }
            }
        }
        if (ans.size() > 0 && ans.back() == '-')
        {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};