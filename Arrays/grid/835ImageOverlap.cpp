class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        int ans = 0;

        auto findAns = [&](int r_offset, int c_offset)
        {
            int count = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int r = i + r_offset;
                    int c = j + c_offset;

                    if (r < 0 || r >= n || c < 0 || c >= n)
                    {
                        continue;
                    }

                    if (img1[i][j] && img2[r][c])
                    {
                        count++;
                    }
                }
            }

            return count;
        };

        for (int row_offset = -n + 1; row_offset < n; row_offset++)
        {
            for (int col_offset = -n + 1; col_offset < n; col_offset++)
            {
                ans = max(ans, findAns(row_offset, col_offset));
            }
        }

        return ans;
    }
};