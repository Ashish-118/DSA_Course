#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution
{
public:
    bool isSafe(vector<pair<int, int>> AddedQueen, int row, int col)
    {
        bool check = true;
        for (auto x : AddedQueen)
        {
            if (x.first == row || x.second == col)
                check = false;
            else if (abs(x.first - row) == abs(x.second - col))
                check = false;
        }
        return check;
    }
    void solve(vector<pair<int, int>> AddedQueen, vector<vector<string>> &ans, int r, int N, int n)
    {
        if (n == 0)
        {

            vector<string> p;
            for (int i = 0; i < N; i++)
            {
                string pattern = "";
                for (int j = 0; j < N; j++)
                {
                    if (AddedQueen[i].second == j)
                    {
                        pattern.push_back('Q');
                        continue;
                    }
                    pattern.push_back('.');
                }
                p.push_back(pattern);
            }

            ans.push_back(p);
            return;
        }

        for (int c = 0; c < N; c++)
        {
            if (isSafe(AddedQueen, r, c))
            {
                AddedQueen.push_back({r, c});
                solve(AddedQueen, ans, r + 1, N, n - 1);
                AddedQueen.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        int i = -1;
        vector<pair<int, int>> AddedQueen;
        vector<vector<string>> ans;
        solve(AddedQueen, ans, 0, n, n);
        return ans;
    }
};

int32_t main()
{
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(4);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << endl;
        }
        cout << endl;
    }

    return 0;
}