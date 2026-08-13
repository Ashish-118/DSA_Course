#include <bits/stdc++.h>
using namespace std;

// Z-Algorithm for Pattern Matching
// z[i] is the length of the longest substring starting from s[i] which is also a prefix of s.
vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> searchPattern(string text, string pattern) {
    string s = pattern + "$" + text;
    vector<int> z = z_function(s);
    vector<int> matches;
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == pattern.length()) {
            matches.push_back(i - pattern.length() - 1);
        }
    }
    return matches;
}

void solve() {
    string text = "abacabadabacaba";
    string pattern = "aba";
    vector<int> matches = searchPattern(text, pattern);
    for (int pos : matches) cout << pos << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
