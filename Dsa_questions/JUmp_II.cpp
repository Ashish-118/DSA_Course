class Solution
{
    int findIndex(int x, int y, vector<int> &nums)
    {
        map<int, int> distance_pos;
        for (int i = x + 1; i <= y; i++)
        {
            distance_pos[i + nums[i]] = i;
        }
        auto maxKey = distance_pos.rbegin()->first;
        return distance_pos[maxKey];
    }

public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int steps = 0;
        int pos = 0;

        while (true)
        {

            if ((pos + nums[pos]) >= (n - 1))
            {
                if (n > 1)
                    steps++;
                return steps;
            }
            else
            {
                pos = findIndex(pos, pos + nums[pos], nums);
                steps++;
            }
        }
    }
};