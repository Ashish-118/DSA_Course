class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> f;

        for (auto x : text) {
            f[x]++;
        }

        return min({f['b'], f['a'], f['n'], f['l'] / 2, f['o'] / 2});
    }
};