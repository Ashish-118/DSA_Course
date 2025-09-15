class Solution
{
public:
    int solve(int prevEnd, int index, vector<vector<int>> &meeting, int n, unordered_map<int, map<int, int>> &dp)
    {
        if (index >= n)
            return 0;
        if (dp[index].count(prevEnd))
            return dp[index][prevEnd];
        int take = -1;
        if (meeting[index][0] >= prevEnd)
        {
            take = meeting[index][2] + solve(meeting[index][1], index + 1, meeting, n, dp);
        }

        int notTake = 0 + solve(prevEnd, index + 1, meeting, n, dp);

        return dp[index][prevEnd] = max(take, notTake);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {

        int n = startTime.size();
        vector<vector<int>> meeting(n);
        for (int i = 0; i < n; i++)
        {
            meeting[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(begin(meeting), end(meeting));

        unordered_map<int, map<int, int>> dp;
        return solve(-1, 0, meeting, n, dp);
    }
}; // tle

// binary search + dp

// Approach-1 (Recur + Memo)
// T.C : O(nlogn), where n is the number of jobs
// S.C : O(n), where n is the number of jobs.
class Solution
{
public:
    int memo[50001];
    int n;
    // find the first job jiska starting point >= currentJob ka end point
    int getNextIndex(vector<vector<int>> &array, int l, int currentJobEnd)
    {
        int r = n - 1;

        int result = n + 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (array[mid][0] >= currentJobEnd)
            { // we can take this task
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>> &array, int i)
    {
        if (i >= n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int next = getNextIndex(array, i + 1, array[i][1]); // lower bound

        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i + 1);

        return memo[i] = max(taken, notTaken);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        n = startTime.size();

        memset(memo, -1, sizeof(memo));

        vector<vector<int>> array(n, vector<int>(3, 0)); //{s, e, p}

        for (int i = 0; i < n; i++)
        {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        auto comp = [&](auto &vec1, auto &vec2)
        {
            return vec1[0] < vec2[0];
        };

        // sort kardo according to sart time
        sort(begin(array), end(array), comp);

        return solve(array, 0);
    }
};
