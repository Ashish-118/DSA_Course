class Solution
{
public:
    int sortableIntegers(vector<int> &nums)
    {
        vector<int> poss;
        int n = nums.size();

        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                poss.push_back(i);
        }
        int ans = 0;

        for (auto x : poss)
        {
            int prev = -1;
            bool check = true;
            vector<int> v;
            for (int i = 0; i < n; i += x)
            {
                int maxi = -1;
                int mini = INT_MAX;
                int minIdx = -1;
                for (int j = i; j < i + x; j++)
                {
                    if (prev > nums[j])
                    {
                        check = false;
                        break;
                    }
                    if (mini > nums[j])
                    {
                        mini = nums[j];
                        minIdx = j;
                    }
                    maxi = max(maxi, nums[j]);
                }
                prev = maxi;
                v.push_back(minIdx);
                if (!check)
                    break;
            }

            if (!check)
                continue;

            int y = 0;

            check = true;

            for (int i = 0; i < n; i += x)
            {
                int prev = -1;
                int num1 = INT_MAX;
                int num2 = INT_MIN;
                for (int j = i; j < v[y]; j++)
                {
                    if (prev > nums[j])
                    {
                        check = false;
                        break;
                    }
                    prev = nums[j];
                    num1 = min(num1, nums[j]);
                }
                if (!check)
                    break;

                prev = -1;
                int index = -1;

                for (int j = v[y] + 1; j < i + x; j++)
                {
                    if (prev > nums[j])
                    {
                        if (nums[v[y]] == nums[j])
                        {
                            index = j;
                        }
                        check = false;
                        break;
                    }
                    prev = nums[j];
                    num2 = max(num2, nums[j]);
                }

                if (!check && index != -1 && num1 == INT_MAX)
                {
                    check = true;
                    for (int j = index; j < i + x; j++)
                    {
                        if (nums[v[y]] != nums[j])
                        {
                            check = false;
                            break;
                        }
                    }
                }

                if (!check)
                    break;

                if (num1 < num2)
                {
                    check = false;
                    break;
                }

                y++;
            }

            if (check)
            {
                ans += x;
            }
        }

        return ans;
    }
};