class Solution {
public:
    int minimumPushes(string word) {
        int tap = 1;

        vector<int> f(26, 0);
        for (auto x : word)
            f[x - 'a']++;

        sort(begin(f), end(f),greater<int>());

        int ans = 0;
        int keys = 0;

        for (int i = 0; i < 26; i++) {
            if (f[i] == 0)
                break;

            ans += (f[i] * tap);
           

            keys++;

            if (keys == 8) {
                keys = 0;
                tap++;
            }
        }

        return ans;
    }
};