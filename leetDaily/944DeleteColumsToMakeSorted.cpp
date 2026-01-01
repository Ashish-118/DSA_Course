class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int count = 0;
        int len = strs[0].length();

        for (int i = 0; i < len; i++)
        {
            char top = strs[0][i];

            for (int j = 1; j < strs.size(); j++)
            {
                if (top > strs[j][i])
                {
                    count++;
                    break;
                }
                top = strs[j][i];
            }
        }

        return count;
    }
};