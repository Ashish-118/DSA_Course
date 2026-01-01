class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();

        auto getNextIndex = [&](int index, int curr_dir)
        {
            int next_index = ((index + nums[index]) % n + n) % n;
            int next_dir = nums[next_index] > 0 ? 1 : -1;

            if (curr_dir != next_dir || index == next_index)
                return -1;

            return next_index;
        };

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            int sp = i, fp = i;
            int curr_dir = nums[i] > 0 ? 1 : -1;

            while (true)
            {
                visited[sp] = true;
                visited[fp] = true;

                sp = getNextIndex(sp, curr_dir);
                fp = getNextIndex(fp, curr_dir);
                if (fp != -1)
                    fp = getNextIndex(fp, curr_dir);

                if (sp == -1 || fp == -1)
                    break;

                if (sp == fp)
                    return true;
            }
        }

        return false;
    }
};
