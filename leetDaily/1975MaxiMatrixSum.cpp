class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long sum = 0;

        int minPosVal = INT_MAX;
        int n = matrix.size();

        int negatives = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < 0)
                    negatives++;
                sum += abs(0 - matrix[i][j]);
                minPosVal = min(abs(0 - matrix[i][j]), minPosVal);
            }
        }

        if (negatives % 2 == 0)
            return sum;
        else
            return sum - 2 * minPosVal;
    }
};