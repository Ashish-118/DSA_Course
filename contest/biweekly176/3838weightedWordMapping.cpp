class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string ans = "";

        for (auto word : words)
        {
            int weight = 0;
            for (auto c : word)
            {
                weight += weights[c - 'a'];
            }
            ans += ('z' - (weight % 26));
        }

        return ans;
    }
};