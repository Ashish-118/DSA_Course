class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();

        sort(begin(asteroids), end(asteroids));
        long long m = mass;

        for (auto x : asteroids) {
            if (m < x)
                return false;
            m += x;
        }
        return true;
    }
};