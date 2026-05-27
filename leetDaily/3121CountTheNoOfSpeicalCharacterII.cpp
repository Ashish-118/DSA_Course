class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<int> capital(26, -1);
        vector<int> small(26, -1);
        for (int i = 0; i < word.length(); i++)
        {
            if ('A' <= word[i] && word[i] <= 'Z')
            {
                if (capital[word[i] - 'A'] == -1)
                    capital[word[i] - 'A'] = i;
            }
            else
            {
                small[word[i] - 'a'] = i;
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++)
        {
            if (capital[i] != -1 && small[i] != -1 && small[i] < capital[i])
            {
                ans++;
            }
        }

        return ans;
    }
};