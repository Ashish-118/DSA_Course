class Solution
{
public:
    string breakPalindrome(string palindrome)
    {

        int n = palindrome.length();
        string ans = "{";
        for (int i = 0; i < palindrome.length(); i++)
        {
            string copy = palindrome;

            for (char c = 'a'; c <= 'z'; c++)
            {
                copy[i] = c;
                string temp = copy;
                reverse(begin(temp), end(temp));
                if (copy != palindrome && copy != temp)
                {

                    ans = min(ans, copy);
                }
            }
        }

        return ans == "{" ? "" : ans;
    }
};

class Solution
{
public:
    string breakPalindrome(string pal)
    {
        int n = pal.length();
        if (n == 1)
            return "";

        for (int i = 0; i < n / 2; i++)
        {
            if (pal[i] != 'a')
            {
                pal[i] = 'a';
                return pal;
            }
        }

        pal[n - 1] = 'b';
        return pal;
    }
};