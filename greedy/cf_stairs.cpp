#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        int ans = 0;
        long long n = 1;

        while (n * (n + 1) / 2 <= x) {
            x -= n * (n + 1) / 2;
            ans++;
            n = 2 * n + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}