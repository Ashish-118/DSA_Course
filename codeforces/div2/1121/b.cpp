#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int solve(int i, int j, vector<int> &v, int m, int n, vector<vector<int>> &dp)
{
    if (j > m)
    {
        return 0;
    }
    else if (i >= n)
    {
        return LLONG_MIN;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int maxi = LLONG_MIN;
    int nextMul = (j < m ? j + 1 : 0);
    // v[i]-nextMul*v[i]
    int take = solve(i + 1, j + 1, v, m, n, dp);
    if (take != LLONG_MIN)
    {
        maxi = max(maxi, j * v[i] - nextMul * v[i] + take);
    }

    int skip = solve(i + 1, j, v, m, n, dp);
    maxi = max(maxi, skip);

    return dp[i][j] = maxi;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m + 1, 0));

    for(int i=0; i<=n; i++){
        dp[i][m]=0;
    }

    for(int i=n-1; i>=0; i--){
        for(int j=m; j>=1; j++){
            int nextMul=(j<m?j+1:0);
            int maxi = LLONG_MIN;
            int take=dp[i+1][j+1];
            if(take!=LLONG_MIN){
               maxi=max(maxi,j*v[i]-nextMul*v[i]+take);
            }
            int skip=dp[i+1][j];
            maxi=max(maxi,skip);
            dp[i][j]=maxi;
        }
    }




    

    int ans = dp[0][1];
    cout << ans << endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}