class Solution {
public:
    int t[20][20];
    int solve(int i, int j, vector<int>& nums) {
        if (i == j) {
            return nums[i];
        } else if (i > j) {
            return 0;
        }

        if (t[i][j] != -1)
            return t[i][j];

        int takeStart = nums[i];

        takeStart += min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));

        int takeEnd = nums[j];

        takeEnd += min(solve(i + 1, j - 1, nums), solve(i, j - 2, nums));

        return t[i][j] = max(takeStart, takeEnd);
    }
    bool predictTheWinner(vector<int>& nums) {
        //-- recursion+memoizaiton
        int total = accumulate(begin(nums), end(nums), 0);
        int n = nums.size();

        // memset(t,-1,sizeof(t));

        // int p1_score=solve(0,n-1,nums);

        // return p1_score>=(total-p1_score);

        // -------- tabulation/ bottomup approach
        memset(t, 0, sizeof(t));

        for (int i = 0; i < n; i++) {
            t[i][i] = nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    int takeStart = nums[i];

                    takeStart +=
                        min((i + 2 < n ? t[i + 2][j] : 0), t[i + 1][j - 1]);

                    int takeEnd = nums[j];

                    takeEnd +=
                        min(t[i + 1][j - 1], (j - 2 >= 0 ? t[i][j - 2] : 0));

                    t[i][j] = max(takeStart, takeEnd);
                }
            }
        }

        int p1_score = t[0][n - 1];

        return p1_score >= (total - p1_score);
    }
};