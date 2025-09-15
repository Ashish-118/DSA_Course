class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        text += ' ';
        int count = 0;
        int n = text.length();
        int i = 0;
        bool check = true;

        while (i < n)
        {

            if (check && text[i] == ' ')
            {
                count++;
            }
            else
            {
                check = true;
            }

            if (brokenLetters.find(text[i]) != string::npos)
            {
                while (i < n && text[i] != ' ')
                    i++;
                i--;
                check = false;
            }

            i++;
        }

        return count;
    }
};