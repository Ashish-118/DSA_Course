class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int rounds = 0;

        unordered_map<int, int> mp;
        for (auto x : tasks)
            mp[x]++;

        for (auto m : mp)
        {

            int byThree_rem = m.second % 3;

            if (byThree_rem != 1)
            {
                rounds += ((m.second / 3) + (byThree_rem != 0 ? 1 : 0));
            }
            else if (m.second >= 4)
            {
                rounds += 2; // 4 tasks each day->2
                m.second -= 4;
                rounds += (m.second / 3);
            }
            else
            {
                return -1;
            }
        }

        return rounds;
    }
};