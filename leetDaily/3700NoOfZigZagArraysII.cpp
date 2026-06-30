class Solution {
public:
    const int MOD = 1000000007;

    vector<vector<long long>> multiply(vector<vector<long long>>& A,
                                       vector<vector<long long>>& B) {
        int rA = A.size();
        int cA = A[0].size();
        int cB = B[0].size();

        vector<vector<long long>> C(rA, vector<long long>(cB, 0));

        for (int i = 0; i < rA; i++) {
            for (int j = 0; j < cB; j++) {
                long long sum = 0;
                for (int k = 0; k < cA; k++) {
                    sum = (sum + A[i][k] * B[k][j]) % MOD;
                }
                C[i][j] = sum;
            }
        }

        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>>& base,
                                    long long exp) {
        int n = base.size();

        vector<vector<long long>> res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        vector<vector<long long>> b = base;

        while (exp > 0) {
            if (exp & 1) {
                res = multiply(res, b);
            }
            b = multiply(b, b);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        int sz = 2 * k;

        vector<vector<long long>> initial(sz, vector<long long>(1, 0));

        for (int v = 1; v <= k; v++) {
            initial[v - 1][0] = k - v;
            initial[k + v - 1][0] = v - 1;
        }

        vector<vector<long long>> T(sz, vector<long long>(sz, 0));

   // filling Transition matrix
   
        // for (int v = 1; v <= k; v++) {
        //     for (int u = 1; u < v; u++) {
        //         T[k + v - 1][u - 1] = 1;
        //     }

        //     for (int u = v + 1; u <= k; u++) {
        //         T[v - 1][k + u - 1] = 1;
        //     }
        // }

 // filling Transition matrix
        for(int OLD=1; OLD<=k; OLD++){
            for(int NEW=OLD+1; NEW<=k; NEW++){
                T[k+NEW-1][OLD-1]=1;
                T[OLD-1][k+NEW-1]=1;
            }
        }

        vector<vector<long long>> Tn = power(T, n - 2);
        vector<vector<long long>> ans = multiply(Tn, initial);

        long long total = 0;

        for (int i = 0; i < sz; i++) {
            total = (total + ans[i][0]) % MOD;
        }

        return (int)total;
    }
};