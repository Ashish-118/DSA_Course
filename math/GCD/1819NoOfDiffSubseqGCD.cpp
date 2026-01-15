class Solution
{
public:
    map<pair<int, int>, bool> visited;

    void solve(int i, int seqGCD, vector<int> &nums, set<int> &st)
    {
        if (i >= nums.size())
            return;

        if (visited.count({i, seqGCD}))
            return;

        visited[{i, seqGCD}] = true;
        st.insert(seqGCD);

        if (seqGCD == -1)
        {

            solve(i + 1, nums[i], nums, st);
            st.insert(nums[i]);
        }
        else
        {

            solve(i + 1, gcd(seqGCD, nums[i]), nums, st);
            st.insert(gcd(seqGCD, nums[i]));
        }

        solve(i + 1, seqGCD, nums, st);
    }

    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        set<int> st;

        solve(0, -1, nums, st);

        return st.size() - 1;
    }
};

// optimal

class Solution
{
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        int maxVal = 0;
        for (int x : nums)
            maxVal = max(maxVal, x);

        vector<bool> present(maxVal + 1, false);
        for (int x : nums)
            present[x] = true;

        int count = 0;

        for (int g = 1; g <= maxVal; g++)
        {
            int currentGCD = 0;

            // check multiples of g
            for (int multiple = g; multiple <= maxVal; multiple += g)
            {
                if (present[multiple])
                {
                    if (currentGCD == 0)
                        currentGCD = multiple;
                    else
                        currentGCD = gcd(currentGCD, multiple);

                    if (currentGCD == g)
                    {
                        count++;
                        break; // no need to continue
                    }
                }
            }
        }

        return count;
    }
};
