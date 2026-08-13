#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix &A, const Matrix &B) {
    int r1 = A.size();
    int c1 = A[0].size();
    int c2 = B[0].size();
    Matrix res(r1, vector<long long>(c2, 0));
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix binpow_matrix(Matrix A, long long p) {
    int n = A.size();
    Matrix res(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1; // Identity matrix
    
    while (p > 0) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}

void solve() {
    // Example: Fibonacci number F_n (F_0 = 0, F_1 = 1)
    // [ F_n   ] = [ 1 1 ] ^ (n-1) * [ F_1 ]
    // [ F_n-1 ]   [ 1 0 ]           [ F_0 ]
    long long n = 10; // Find 10th fibonacci
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    Matrix T = {{1, 1}, {1, 0}};
    T = binpow_matrix(T, n - 1);
    
    // F_n is T[0][0] * F_1 + T[0][1] * F_0 = T[0][0] * 1 + T[0][1] * 0
    cout << T[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
