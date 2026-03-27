class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> temp = mat;
        k = k % mat[0].size();

        for (int i = 0; i < mat.size(); i++)
        {
            if (i % 2 == 0)
            {
                reverse(temp[i].begin(), temp[i].begin() + k);
                reverse(temp[i].begin() + k, temp[i].end());
                reverse(temp[i].begin(), temp[i].end());
            }
            else
            {
                reverse(temp[i].begin(), temp[i].begin() + k);
                reverse(temp[i].begin() + k, temp[i].end());
                reverse(temp[i].begin(), temp[i].end());
            }
        }

        return temp == mat;
    }
};