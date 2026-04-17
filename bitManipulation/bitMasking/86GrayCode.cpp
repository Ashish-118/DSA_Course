class Solution
{
public:
    vector<bool> visited;
    vector<int> ans;
    void solve(int val, int n)
    {
        visited[val] = true;
        ans.push_back(val);

        for (int i = 0; i < n; i++)
        {
            int ngb = val ^ (1 << i);
            if (!visited[ngb])
            {
                solve(ngb, n);
            }
        }
    }
    vector<int> grayCode(int n)
    {
        visited.assign(pow(2, n), false);
        solve(0, n);

        return ans;
    }
};