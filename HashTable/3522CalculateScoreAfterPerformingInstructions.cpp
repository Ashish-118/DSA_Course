class Solution
{
public:
    long long calculateScore(vector<string> &instructions,
                             vector<int> &values)
    {

        int i = 0;
        long long score = 0;
        unordered_map<int, bool> mp;
        int n = instructions.size();

        while (i >= 0 && i < n)
        {
            if (mp[i])
            {
                break;
            }
            mp[i] = true;

            if (instructions[i] == "add")
            {
                score += values[i];
                i++;
            }
            else
            {
                i = i + values[i];
            }
        }

        return score;
    }
};