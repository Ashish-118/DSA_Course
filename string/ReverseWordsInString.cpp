class Solution
{
public:
    string reverseWords(string s)
    {
        while (!s.empty() && s.front() == ' ')
            s.erase(s.begin());

        while (!s.empty() && s.back() == ' ')
            s.pop_back();

        int i = 0, spaces = 0;
        while (i < s.length())
        {
            if (s[i] == ' ')
                spaces++;
            else
                spaces = 0;

            if (spaces >= 2)
            {
                s.erase(s.begin() + i);
            }
            else
            {
                i++;
            }
        }

        reverse(begin(s), end(s));

        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(begin(s) + start, begin(s) + i);
                start = i + 1;
            }
        }
        reverse(begin(s) + start, end(s));

        return s;
    }
};