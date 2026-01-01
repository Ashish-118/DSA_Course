class NumMatrix
{
public:
    vector<vector<int>> row_prefix;
    vector<vector<int>> rectangle_prefix;

    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();

        row_prefix = vector<vector<int>>(n, vector<int>(m, 0));
        rectangle_prefix = vector<vector<int>>(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++)
        {

            for (int col = 0; col < m; col++)
            {
                row_prefix[row][col] =
                    matrix[row][col] + (col > 0 ? row_prefix[row][col - 1] : 0);
            }
        }

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                rectangle_prefix[row][col] =
                    row_prefix[row][col] +
                    (row > 0 ? rectangle_prefix[row - 1][col] : 0);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return rectangle_prefix[row2][col2] -
               (col1 > 0 ? rectangle_prefix[row2][col1 - 1] : 0) -
               (row1 > 0 ? rectangle_prefix[row1 - 1][col2] : 0) +
               ((row1 > 0 && col1 > 0) ? rectangle_prefix[row1 - 1][col1 - 1]
                                       : 0);
    }
};

/**
 * Your NumMatrix  object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */