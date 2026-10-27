class Solution
{
public:
    vector<string> createGrid(int m, int n)
    {
        vector<string> ans;
        for (int i = 0; i < m; i++)
        {
            string s;
            if (i == 0)
            {
                s = string(n, '.');
            }
            else
            {
                s = string(n, '#');
            }

            ans.push_back(s);
        }

        for (int i = 0; i < m; i++)
        {
            ans[i][n - 1] = '.';
        }

        return ans;
    }
};