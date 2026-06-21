class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int ans = 0;

        for (auto x : costs) {
            if (coins < x) {
                break;
            }
            ans++;

            coins -= x;
        }

        return ans;
    }
};