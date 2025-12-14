class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int i, int prev, int n, vector<int> &nums)
    {
        if (i >= n)
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int take = 0;
        if (prev == -1 || nums[i] % nums[prev] == 0)
        {
            take = 1 + solve(i + 1, i, n, nums);
        }
        int notTake = solve(i + 1, prev, n, nums);

        return dp[i][prev + 1] = max(take, notTake);
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
        solve(0, -1, nums.size(), nums);

        for (int i = 0; i < dp.size(); i++)
        {

            for (int j = 0; j < dp[i].size(); j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return {};
    }
};

// to get the subset

// Approach-1 (Using Brute Force same as LIS)
// T.C : O(2^n) without memoization
// S.C : O(n)
class Solution
{
public:
    void generate(int idx, vector<int> &nums, vector<int> &result, vector<int> &temp, int prev)
    {
        if (idx >= nums.size())
        {
            if (temp.size() > result.size())
            {
                result = temp;
            }
            return;
        }

        if (prev == -1 || nums[idx] % prev == 0)
        {
            temp.push_back(nums[idx]);
            generate(idx + 1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }

        generate(idx + 1, nums, result, temp, prev);
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(begin(nums), end(nums));

        vector<int> result;
        vector<int> temp;
        generate(0, nums, result, temp, -1);

        return result;
    }
};

// bottom up

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int last_chosen_index = 0;
        int maxL = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (t[i] < t[j] + 1)
                    {
                        t[i] = t[j] + 1;
                        prev_idx[i] = j;
                    }

                    if (t[i] > maxL)
                    {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while (last_chosen_index >= 0)
        {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return result;
    }
};
