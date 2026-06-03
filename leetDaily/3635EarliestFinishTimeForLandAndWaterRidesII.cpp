class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int l = landStartTime.size();
        int w = waterStartTime.size();

        vector<vector<int>> land, water;

        for (int i = 0; i < l; i++) {
            land.push_back({landStartTime[i],
                            landStartTime[i] + landDuration[i],
                            landDuration[i]});
        }

        for (int i = 0; i < w; i++) {
            water.push_back({waterStartTime[i],
                             waterStartTime[i] + waterDuration[i],
                             waterDuration[i]});
        }

        sort(begin(land), end(land));
        sort(begin(water), end(water));

        // Water suffix/prefix
        vector<int> w_suffix(w), w_prefix(w);

        w_suffix[w - 1] = water[w - 1][1];

        for (int i = w - 2; i >= 0; i--) {
            w_suffix[i] = min(w_suffix[i + 1], water[i][1]);
        }

        w_prefix[0] = water[0][2];

        for (int i = 1; i < w; i++) {
            w_prefix[i] = min(w_prefix[i - 1], water[i][2]);
        }

        // Land suffix/prefix
        vector<int> l_suffix(l), l_prefix(l);

        l_suffix[l - 1] = land[l - 1][1];

        for (int i = l - 2; i >= 0; i--) {
            l_suffix[i] = min(l_suffix[i + 1], land[i][1]);
        }

        l_prefix[0] = land[0][2];

        for (int i = 1; i < l; i++) {
            l_prefix[i] = min(l_prefix[i - 1], land[i][2]);
        }

        int ans = INT_MAX;

        auto cmp = [&](const vector<int>& ride, int x) { return ride[0] < x; };

        //--------------------------------------------------
        // LAND -> WATER
        //--------------------------------------------------
        for (int i = 0; i < l; i++) {

            int endTime = land[i][1];

            int it = lower_bound(begin(water), end(water), endTime, cmp) -
                     begin(water);

            if (it < w) {
                ans = min(ans, w_suffix[it]);
            }

            if (it > 0) {
                ans = min(ans, endTime + w_prefix[it - 1]);
            }
        }

        //--------------------------------------------------
        // WATER -> LAND
        //--------------------------------------------------
        for (int i = 0; i < w; i++) {

            int endTime = water[i][1];

            int it =
                lower_bound(begin(land), end(land), endTime, cmp) - begin(land);

            if (it < l) {
                ans = min(ans, l_suffix[it]);
            }

            if (it > 0) {
                ans = min(ans, endTime + l_prefix[it - 1]);
            }
        }

        return ans;
    }
};