#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

int tabulation(int n, string s)
{

 
    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(4, vector<int>(2, 0)));

 
    for (int prevSum = 0; prevSum < 4; prevSum++)
    {
        for (int prevVal = 0; prevVal < 2; prevVal++)
        {
            dp[n][prevSum][prevVal] = 1;
        }
    }

   
    for (int i = n - 1; i >= 0; i--)
    {

        for (int prevSum = 0; prevSum < 4; prevSum++)
        {

            for (int prevVal = 0; prevVal < 2; prevVal++)
            {

                int ans = 0;

                if (s[i] != '?')
                {

                    int curr = s[i] - '0';

                  
                    if (i != 0 && prevSum == curr + prevVal)
                    {
                        dp[i][prevSum][prevVal] = 0;
                    }
                    else
                    {

                        int newPrevSum;

                        if (i != 0)
                            newPrevSum = curr + prevVal;
                        else
                            newPrevSum = prevSum;

                        ans = dp[i + 1][newPrevSum][curr];

                        dp[i][prevSum][prevVal] = ans;
                    }
                }
                else
                {

                    if (i == 0)
                    {

                        // ? -> 0
                        ans = (ans + dp[i + 1][3][0]) % mod;

                        // ? -> 1
                        ans = (ans + dp[i + 1][3][1]) % mod;
                    }
                    else
                    {

                        // ? -> 1
                        if (prevSum != (1 + prevVal))
                        {
                            ans = (ans +
                                   dp[i + 1][1 + prevVal][1]) %
                                  mod;
                        }

                        // ? -> 0
                        if (prevSum != (0 + prevVal))
                        {
                            ans = (ans +
                                   dp[i + 1][prevVal][0]) %
                                  mod;
                        }
                    }

                    dp[i][prevSum][prevVal] = ans;
                }
            }
        }
    }

    // Your original solve would be called initially with:
    // solve(0, 0, 3, ...)
    return dp[0][3][0];
}

int main()
{

    int t;
    cin >> t;
    
    while (t--)
    {
       
        
        int n;
        cin >> n;


        string s;
        cin >> s;

        cout << tabulation(n, s) << endl;

      
    }

    return 0;
}