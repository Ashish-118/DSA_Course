class Solution
{
public:
    string maskPII(string s)
    {
        string ans = "";
        int n = s.length();
        if (s.find('@') != string::npos)
        {
            transform(s.begin(), s.end(), s.begin(), ::tolower);

            auto pos = s.find('@');

            ans += (tolower(s[0]));
            ans += "*****";
            ans += (tolower(s[pos - 1]));

            ans += s.substr(pos);
        }
        else
        {
            string p = "";

            for (auto x : s)
            {
                if (isdigit(x))
                    p += x;
            }

            int countryCode = p.length() - 10;
            if (countryCode > 0)
            {
                ans += "+" + string(countryCode, '*') + "-";
            }
            ans += "***-***-";
            ans += p.substr(p.length() - 4);
        }

        return ans;
    }
};