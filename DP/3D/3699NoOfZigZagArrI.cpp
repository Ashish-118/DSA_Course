#define mod 1000000007
class Solution {
public:
    // int t[2002][2001][2];
    // int solve(int i, int l, int r, int INC, int n, int prev) {
    //     if (i >= n) {
    //         return 1;
    //     }
    //     if (t[i][prev][INC] != -1)
    //         return t[i][prev][INC];
    //     long long result = 0;
    //     if (INC) {
    //         for (int j = prev + 1; j <= r; j++) {
    //             result = (result + solve(i + 1, l, r, false, n, j)) % mod;
    //         }
    //     } else {
    //         for (int j = l; j < prev; j++) {
    //             result = (result + solve(i + 1, l, r, true, n, j)) % mod;
    //         }
    //     }

    //     return t[i][prev][INC] = result;
    // }

    int zigZagArrays(int n, int l, int r) {

        r = r - l + 1;
        l = 1;

        // memset(t, 0, sizeof(t));

        // for (int j = l; j <= r; j++) { // for 0th index
        //     // inc
        //     ans = (ans + solve(1, l, r, true, n, j)) % mod;

        //     // dec
        //     ans = (ans + solve(1, l, r, false, n, j)) % mod;
        // }

        // tabulation

        // for (int prev = l; prev <= r; prev++) {
        //     t[n][prev][1] = 1;
        //     t[n][prev][0] = 1;
        // }

        // for (int i = n - 1; i >= 1; i--) {
        //     for (int prev = l; prev <= r; prev++) {
        //         for (int INC = 0; INC < 2; INC++) {
        //             long long result = 0;
        //             if (INC) {
        //                 for (int j = prev + 1; j <= r; j++) {
        //                     result = (result + t[i + 1][j][false]) % mod;
        //                 }
        //             } else {
        //                 for (int j = l; j < prev; j++) {
        //                     result = (result + t[i + 1][j][true]) % mod;
        //                 }
        //             }

        //             t[i][prev][INC] = result;
        //         }
        //     }
        // }

        // int ans=0;

        // for (int j = l; j <= r; j++) { // for 0th index
        //     // inc
        //     ans = (ans + t[1][j][true]) % mod;

        //     // dec
        //     ans = (ans + t[1][j][false]) % mod;
        // }

        // optimising tabulation

        vector<vector<vector<long long>>> t(
            n + 1, vector<vector<long long>>(2, vector<long long>(r + 1, 0)));

        t[n][1][l] = 1;
        t[n][0][l] = 1;
        for (int prev = l + 1; prev <= r; prev++) {
            t[n][1][prev] = t[n][1][prev - 1] + 1;
            t[n][0][prev] = t[n][0][prev - 1] + 1;
        }

        for (int i = n - 1; i >= 1; i--) {
            for (int INC = 0; INC < 2; INC++) {

                for (int prev = l; prev <= r; prev++) {
                    long long result = 0;
                    if (INC) {
                        result =
                            (t[i + 1][0][r] - t[i + 1][0][prev] + mod) % mod;
                    } else {
                        result = t[i + 1][1][prev - 1];
                    }

                    t[i][INC][prev] = (result + t[i][INC][prev - 1]) % mod;
                }
            }
        }

        long long ans = (t[1][1][r] + t[1][0][r]) % mod;

        return ans;
    }
};