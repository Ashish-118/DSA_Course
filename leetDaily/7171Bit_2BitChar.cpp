class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        bool ans = false;
        int n = bits.size();

        for (int i = 0; i < bits.size(); i++)
        {
            if (i == n - 1)
            {
                ans = true;
            }
            if (bits[i] == 1)
                i++;
        }

        return ans;
    }
};