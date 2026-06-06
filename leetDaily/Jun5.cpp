class Solution {
public:
   
    using ll = long long;
    vector<vector<vector<vector<vector<vector<pair<ll, ll>>>>>>> t;
    pair<long long, long long> solve(int i, int prev, int pattern, string lo,
                                     string up, int tightUp, int tightLo,
                                     int leadingZeroes) {
        if (i >= up.length()) {
            return {1, 0};
        }
        if (t[i][prev][pattern][tightUp][tightLo][leadingZeroes] !=
            make_pair(-1LL, -1LL)) {
            return t[i][prev][pattern][tightUp][tightLo][leadingZeroes];
        }

        int lower = tightLo ? lo[i] - '0' : 0;
        int upper = tightUp ? up[i] - '0' : 9;

        long long ans = 0;
        long long count = 0;

        for (int r = lower; r <= upper; r++) {
            if (leadingZeroes && r == 0) {
                auto v1 = solve(i + 1, 10, 0, lo, up, tightUp && (r == upper),
                                tightLo && (r == lower), 1);
                ans += v1.second;
                count += v1.first;
            } else if (prev == 10) {
                auto v2 = solve(i + 1, r, 0, lo, up, tightUp && (r == upper),
                                tightLo && (r == lower), 0);
                ans += v2.second;
                count += v2.first;
            } else {

                auto val =  make_pair(-1LL, -1LL);
                if (prev > r) {
                    val = solve(i + 1, r, 2, lo, up, tightUp && (r == upper),
                                tightLo && (r == lower), 0);
                } else if (prev < r) {
                    val = solve(i + 1, r, 1, lo, up, tightUp && (r == upper),
                                tightLo && (r == lower), 0);
                } else {
                    val = solve(i + 1, r, 0, lo, up, tightUp && (r == upper),
                                tightLo && (r == lower), 0);
                }
                if (pattern == 0) {
                    ans += val.second;
                    count += val.first;
                } else if (pattern == 1) {
                    if (prev > r) {

                        ans = ans + val.first + val.second;
                        count += val.first;
                    } else {
                        ans += val.second;
                        count += val.first;
                    }
                } else if (pattern == 2) {
                    if (prev < r) {
                        ans = ans + val.first + val.second;
                        count += val.first;
                    } else {
                        ans += val.second;
                        count += val.first;
                    }
                }
            }
        }

        return t[i][prev][pattern][tightUp][tightLo][leadingZeroes] = {count,
                                                                       ans};
    }

    long long totalWaviness(long long num1, long long num2) {
        string str = to_string(num1), up = to_string(num2);
        string lo = "";

        for (int i = 0; i < up.length() - str.length(); i++) {
            lo += "0";
        }

        lo += str;

        cout << lo << " " << up << endl;
        t.assign(
            16,
            vector<vector<vector<vector<vector<pair<ll, ll>>>>>>(
                11, vector<vector<vector<vector<pair<ll, ll>>>>>(
                        3, vector<vector<vector<pair<ll, ll>>>>(
                               2, vector<vector<pair<ll, ll>>>(
                                      2, vector<pair<ll, ll>>(2, {-1, -1}))))));
        return solve(0, 10, 0, lo, up, 1, 1, 1).second;
    }
};