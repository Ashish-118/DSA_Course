class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int n = mat.size();
        bool check = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (target[i][j] != mat[i][j])
                {
                    check = false;
                    break;
                }
            }
        }

        if (check)
            return true;

        check = true;

        int i = 0, j = 0;
        for (int col = 0; col < n; col++)
        {
            j = 0;
            for (int row = n - 1; row >= 0; row--)
            {
                if (target[i][j++] != mat[row][col])
                {
                    check = false;
                    break;
                }
            }
            i++;
        }

        if (check)
            return true;
        check = true;
        i = 0, j = 0;
        for (int row = n - 1; row >= 0; row--)
        {
            j = 0;
            for (int col = n - 1; col >= 0; col--)
            {
                if (target[i][j++] != mat[row][col])
                {
                    check = false;
                    break;
                }
            }
            i++;
        }

        if (check)
            return true;

        check = true;
        i = 0, j = 0;
        for (int col = n - 1; col >= 0; col--)
        {
            j = 0;
            for (int row = 0; row < n; row++)
            {
                if (target[i][j++] != mat[row][col])
                {
                    check = false;
                    break;
                }
            }
            i++;
        }

        return check;
    }
};