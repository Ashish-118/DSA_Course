class Solution
{
public:
    string reverseVowels(string s)
    {
        string vowels = "aeiouAEIOU";

        int i = 0, j = s.length() - 1;

        while (i < j)
        {
            if (vowels.find(s[i]) == string::npos)
            {
                i++;
            }
            else if (vowels.find(s[j]) == string::npos)
            {
                j--;
            }
            else
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};