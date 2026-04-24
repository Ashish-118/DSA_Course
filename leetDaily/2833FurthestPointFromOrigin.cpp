class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        char dir = 'R';

        int right = 0, left = 0;

        for (auto x : moves)
        {
            if (x == 'L')
                left++;
            if (x == 'R')
                right++;
        }

        if (left > right)
            dir = 'L';

        int n = moves.size();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (moves[i] != '_' && dir != moves[i])
            {
                ans--;
            }
            else
            {
                ans++;
            }
        }

        return ans;
    }
};