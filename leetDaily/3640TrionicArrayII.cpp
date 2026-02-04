class Solution
{
public:
    long long maxSumTrionic(vector<int> &nums)
    {
        vector<pair<pair<int, int>, pair<int, int>>> increasingPairs;
        set<pair<int, int>> decreasingPairs;

        int l = 0, p = 0;
        bool check = false;
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        long long prev = -1e13;
        int idx1 = -1;
        int idx2 = 0;
        bool allow = true;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];

            if (nums[i - 1] < nums[i])
            {
                p = i;
                check = true;
                if (prefix[i] > prev)
                {
                    prev = prefix[i];
                    idx1 = i;
                }

                if (nums[i] >= 0 && allow)
                {
                    if (nums[idx2] >= 0)
                    {
                        continue;
                    }
                    idx2 = i;
                    allow = false;
                }
            }
            else
            {
                if (check)
                {
                    increasingPairs.push_back({{l, p}, {idx1, idx2}});
                    idx1 = -1;

                    prev = -1e13;
                    allow = true;
                    check = false;
                }
                idx2 = i;
                l = i;
            }
        }

        if (check)
        {
            increasingPairs.push_back({{l, p}, {idx1, idx2}});
        }

        l = 0;
        p = 0;
        check = false;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                p = i;
                check = true;
            }
            else
            {
                if (check)
                {
                    decreasingPairs.insert({l, p});
                    check = false;
                }
                l = i;
            }
        }
        if (check)
        {
            decreasingPairs.insert({l, p});
        }

        long long maxi = -1e18;

        for (int i = 1; i < increasingPairs.size(); i++)
        {

            auto pair1 = increasingPairs[i - 1].first;
            auto p1 = increasingPairs[i - 1].second;

            auto pair2 = increasingPairs[i].first;
            auto p2 = increasingPairs[i].second;

            if ((pair1.second + 1 == pair2.first) &&
                    nums[pair1.second] > nums[pair2.first] ||
                decreasingPairs.find({pair1.second, pair2.first}) !=
                    decreasingPairs.end())
            {

                long long increasingSum1 = 0;

                if (nums[pair1.second] < 0)
                {
                    increasingSum1 +=
                        (nums[pair1.second] + nums[pair1.second - 1]);
                }
                else
                {

                    if (p1.second <= 0)
                    {
                        increasingSum1 = prefix[pair1.second];
                    }
                    else if (p1.second == pair1.second)
                    {
                        increasingSum1 =
                            (nums[pair1.second] + nums[pair1.second - 1]);
                    }
                    else
                    {
                        increasingSum1 =
                            prefix[pair1.second] - prefix[p1.second - 1];
                    }
                }

                long long decreasingSum =
                    ((pair1.second + 1) == (pair2.first)
                         ? 0
                         : prefix[pair2.first - 1] - prefix[pair1.second]);

                long long increasingSum2 = 0;

                if (nums[pair2.second] < 0)
                {
                    increasingSum2 +=
                        (nums[pair2.first] + nums[pair2.first + 1]);
                }
                else
                {

                    increasingSum2 =
                        (prefix[p2.first] - prefix[pair2.first - 1]);
                }

                maxi =
                    max(maxi, increasingSum1 + increasingSum2 + decreasingSum);
            }
        }

        return maxi;
    }
};

// time complexity : O(nlogn) due to set and vector of pairs
// space complexity : O(n) to store increasing and decreasing pairs