class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;

        while (r1 < r2)
        {

            vector<int> items;
            int idx = 0;

            for (int c = c1; c < c2; c++)
            {
                items.push_back(matrix[r1][c]);
            }
            for (int r = r1; r < r2; r++)
            {
                items.push_back(matrix[r][c2]);
                matrix[r][c2] = items[idx++];
            }
            for (int c = c2; c > c1; c--)
            {
                items.push_back(matrix[r2][c]);
                matrix[r2][c] = items[idx++];
            }
            for (int r = r2; r > r1; r--)
            {
                items.push_back(matrix[r][c1]);
                matrix[r][c1] = items[idx++];
            }

            for (int c = c1; c < c2; c++)
            {
                matrix[r1][c] = items[idx++];
            }

            r1++;
            r2--;
            c1++;
            c2--;
        }
    }
};