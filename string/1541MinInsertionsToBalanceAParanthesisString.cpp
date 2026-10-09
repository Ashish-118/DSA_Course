class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.length();

        int track = 0;
        int minInsertions = 0;

        for (int i = 0; i < n; i++)
        {
            track += (s[i] == '(' ? 2 : -1);

            if (track < 0)
            {
                track += 2;
                minInsertions++;
            }
            else if (s[i] == '(' && track & 1)
            {
                track--;
                minInsertions++;
            }
        }

        return minInsertions + track;
    }
};