class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<int> commonSequenceFromEnd(n + 1, 0);

        int i = n - 1, j = m - 1;

        while (i >= 0 && j >= 0)
        {
            if (word1[i] == word2[j])
            {
                commonSequenceFromEnd[i] = commonSequenceFromEnd[i + 1] + 1;
                i--;
                if (j != 0)
                    j--;
            }
            else
            {
                commonSequenceFromEnd[i] += commonSequenceFromEnd[i + 1];
                i--;
            }
        }

        i = 0;
        j = 0;

        vector<int> ans;
        bool taken = false;

        while (i < n && j < m)
        {

            if (word1[i] == word2[j])
            {

                ans.push_back(i);
                i++;
                j++;
            }
            else
            {

                if (!taken)
                {
                    int remaining = m - j - 1;

                    if (remaining <= commonSequenceFromEnd[i + 1])
                    {

                        taken = true;
                        ans.push_back(i);
                        i++;
                        j++;
                    }
                    else
                    {
                        i++;
                    }
                }
                else
                {
                    i++;
                }
            }
        }

        if (ans.size() != word2.length())
            return {};

        return ans;
    }
};