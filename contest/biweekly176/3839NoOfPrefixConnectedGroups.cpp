class Solution
{
public:
    int prefixConnected(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;

        for (auto word : words)
        {
            if (word.length() >= k)
            {
                mp[word.substr(0, k)]++;
            }
        }

        int count = 0;
        for (auto m : mp)
        {
            if (m.second >= 2)
                count++;
        }

        return count;
    }
};