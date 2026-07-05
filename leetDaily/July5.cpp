// #define mod 1000000007

// class Solution {
// public:
//     int t1[101][101];
//     int t2[101][101][9001];

//     vector<vector<int>> dir = {{0, -1}, {-1, 0}, {-1, -1}};

//     int maxSum(int i, int j, vector<string>& board) {
//         if (i == 0 && j == 0)
//             return 0;

//         if (t1[i][j] != -1)
//             return t1[i][j];

//         int ans = INT_MIN;

//         int val = (board[i][j] == 'S' || board[i][j] == 'E')
//                       ? 0
//                       : board[i][j] - '0';

//         for (auto &d : dir) {
//             int x = i + d[0];
//             int y = j + d[1];

//             if (x >= 0 && y >= 0 &&
//                 x < board.size() && y < board.size() &&
//                 board[x][y] != 'X') {

//                 int ret = maxSum(x, y, board);

//                 if (ret != INT_MIN)
//                     ans = max(ans, ret + val);
//             }
//         }

//         return t1[i][j] = ans;
//     }

//     int count(int i, int j, vector<string>& board, int target) {
//         if (target < 0)
//             return 0;

//         if (i == 0 && j == 0)
//             return target == 0;

//         if (t2[i][j][target] != -1)
//             return t2[i][j][target];

//         long long ways = 0;

//         int val = (board[i][j] == 'S' || board[i][j] == 'E')
//                       ? 0
//                       : board[i][j] - '0';

//         for (auto &d : dir) {
//             int x = i + d[0];
//             int y = j + d[1];

//             if (x >= 0 && y >= 0 &&
//                 x < board.size() && y < board.size() &&
//                 board[x][y] != 'X') {

//                 ways = (ways + count(x, y, board, target - val)) % mod;
//             }
//         }

//         return t2[i][j][target] = ways;
//     }

//     vector<int> pathsWithMaxScore(vector<string>& board) {
//         memset(t1, -1, sizeof(t1));
//         memset(t2, -1, sizeof(t2));

//         int n = board.size();

//         int target = maxSum(n - 1, n - 1, board);

//         if (target == INT_MIN)
//             return {0, 0};

//         int ways = count(n - 1, n - 1, board, target);

//         return {target, ways};
//     }
// };


using PII = pair<int, int>;

class Solution {
private:
    static constexpr int mod = (int)1e9 + 7;

public:
    void update(vector<vector<PII>>& dp, int n, int x, int y, int u, int v) {
        if (u >= n || v >= n || dp[u][v].first == -1) {
            return;
        }
        if (dp[u][v].first > dp[x][y].first) {
            dp[x][y] = dp[u][v];
        } else if (dp[u][v].first == dp[x][y].first) {
            dp[x][y].second += dp[u][v].second;
            if (dp[x][y].second >= mod) {
                dp[x][y].second -= mod;
            }
        }
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<PII>> dp(n, vector<PII>(n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1};
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (!(i == n - 1 && j == n - 1) && board[i][j] != 'X') {
                    update(dp, n, i, j, i + 1, j);
                    update(dp, n, i, j, i, j + 1);
                    update(dp, n, i, j, i + 1, j + 1);
                    if (dp[i][j].first != -1) {
                        dp[i][j].first +=
                            (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                    }
                }
            }
        }
        return dp[0][0].first == -1
                   ? vector<int>{0, 0}
                   : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};