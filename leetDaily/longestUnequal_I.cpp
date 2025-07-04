class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> ans;
        int check = groups[0];
        for (int i = 0; i < groups.size(); i++)
        {
            if (!(groups[i] ^ check))
            {
                ans.push_back(words[i]);
                check = (check == 0 ? 1 : 0);
            }
        }

        return ans;
    }
};