class Solution
{
public:
    double solve(vector<vector<int>> &classes, int extra, int i, int n, vector<vector<double>> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i][extra] != -1)
            return dp[i][extra];
        int numerator = classes[i][0];
        int denominator = classes[i][1];
        double ans = -1e9;
        for (int k = 0; k <= extra; k++)
        {
            ans = max(ans, (double)(numerator + k) / (denominator + k) + solve(classes, extra - k, i + 1, n, dp));
        }

        return dp[i][extra] = ans;
    }
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        int n = classes.size();
        vector<vector<double>> dp(n, vector<double>(extraStudents + 1, -1));
        return (double)solve(classes, extraStudents, 0, n, dp) / n;
    }
}; // recursion + memoization

// tabulation or bottom-up approach

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    int n = classes.size();
    // vector<vector<double>> dp(n,vector<double>(extraStudents+1,-1));
    vector<vector<double>> dp(n + 1, vector<double>(extraStudents + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        int numerator = classes[i][0];
        int denominator = classes[i][1];
        for (int extra = 0; extra <= extraStudents; extra++)
        {
            double best = -1e9;
            for (int k = 0; k <= extra; k++)
            {
                best = max(best,
                           (double)(numerator + k) / (denominator + k) + dp[i + 1][extra - k]);
            }
            dp[i][extra] = best;
        }
    }

    return dp[0][extraStudents] / n;
}

// space optimization

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    int n = classes.size();
    // vector<vector<double>> dp(n,vector<double>(extraStudents+1,-1));
    vector<double> curr(extraStudents + 1, 0);
    vector<double> prev(extraStudents + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int numerator = classes[i][0];
        int denominator = classes[i][1];
        for (int extra = 0; extra <= extraStudents; extra++)
        {
            double best = -1e9;
            for (int k = 0; k <= extra; k++)
            {
                best = max(best,
                           (double)(numerator + k) / (denominator + k) + prev[extra - k]);
            }
            curr[extra] = best;
        }
        prev = curr;
    }

    return prev[extraStudents] / n;
}

// the most optimized approach using max heap

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        // Lambda to calculate the gain of adding an extra student
        auto calculateGain = [](int passes, int totalStudents)
        {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        // Max heap to store (-gain, passes, totalStudents)
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto &singleClass : classes)
        {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                          {singleClass[0], singleClass[1]}});
        }

        // Distribute extra students
        while (extraStudents--)
        {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!maxHeap.empty())
        {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};