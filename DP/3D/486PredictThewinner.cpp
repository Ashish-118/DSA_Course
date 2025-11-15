class Solution
{
public:
    using p = pair<int, int>;

    vector<vector<vector<p>>> dp;
    pair<int, int> solve(vector<int> &nums, int i, int j, int player)
    {
        if (i > j)
            return {0, 0};

        if (dp[player][i][j].first != -1)
            return dp[player][i][j];

        auto get1 = solve(nums, i + 1, j, !player);
        auto get2 = solve(nums, i, j - 1, !player);
        p scores; // p1,p2
        if (player == 1)
        {
            // p1
            int score1 = nums[i] + get1.first;
            int score2 = nums[j] + get2.first;
            if (score2 > score1)
            {
                scores = {score2, get2.second};
            }
            else
            {
                scores = {score1, get1.second};
            }

            cout << "p1 " << scores.first << " " << scores.second << endl;
        }
        else
        {
            // p2
            int score1 = nums[i] + get1.second;
            int score2 = nums[j] + get2.second;
            if (score2 > score1)
            {
                scores = {get2.first, score2};
            }
            else
            {
                scores = {get1.first, score1};
            }
            cout << "p2 " << scores.first << " " << scores.second << endl;
        }

        return dp[player][i][j] = scores;
    }
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        dp.assign(2, vector<vector<p>>(n, vector<p>(n, {-1, -1})));
        auto get = solve(nums, 0, n - 1, 1);

        if (get.first >= get.second)
        {
            cout << get.first << " " << get.second << endl;
            return true;
        }
        else
            return false;
    }
};

// another optimal recurrsion + memo

class Solution
{
public:
    int n;
    int t[23][23];
    int solve(vector<int> &nums, int l, int r)
    {

        if (l > r)
            return 0;

        if (l == r)
            return nums[l];

        if (t[l][r] != -1)
            return t[l][r];

        int take_left = nums[l] + min(solve(nums, l + 2, r), solve(nums, l + 1, r - 1));

        int take_right = nums[r] + min(solve(nums, l, r - 2), solve(nums, l + 1, r - 1));

        return t[l][r] = max(take_left, take_right);
    }

    bool predictTheWinner(vector<int> &nums)
    {

        memset(t, -1, sizeof(t));

        n = nums.size();

        int total = accumulate(begin(nums), end(nums), 0);

        int player1 = solve(nums, 0, n - 1);
        int player2 = total - player1;

        return player1 >= player2;
    }
};
