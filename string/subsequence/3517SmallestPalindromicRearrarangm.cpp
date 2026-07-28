class Solution
{
public:
    string smallestPalindrome(string s)
    {

        vector<int> f(26, 0);
        int n = s.length();
        char oddFreqChar = ' ';

        for (auto x : s)
        {
            f[x - 'a']++;
        }

        int x = 0, y = n - 1;

        for (int i = 0; i < 26; i++)
        {

            if (f[i] == 0)
                continue;

            if (f[i] & 1)
            {
                oddFreqChar = i + 'a';
            }

            int noOfChar = f[i] / 2;

            while (noOfChar)
            {

                s[x] = i + 'a';
                s[y] = i + 'a';
                x++;
                y--;
                noOfChar--;
            }

            if (x == y)
            {
                s[x] = oddFreqChar;
            }
        }

        return s;
    }
};