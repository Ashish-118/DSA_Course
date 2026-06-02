class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;

        int l = landStartTime.size(), w = waterStartTime.size();

        for (int i = 0; i < l; i++) {
            int time = landStartTime[i] + landDuration[i];
            int mini = INT_MAX;
            for (int j = 0; j < w; j++) {
                mini =
                    min(mini, max(time, waterStartTime[j]) + waterDuration[j]);
            }

            ans = min(ans, mini);
        }

        for (int i = 0; i < w; i++) {
            int time = waterStartTime[i] + waterDuration[i];
            int mini = INT_MAX;
            for (int j = 0; j < l; j++) {
                mini =
                    min(mini, max(time, landStartTime[j]) + landDuration[j]);
            }

            ans = min(ans, mini);
        }

        return ans;
    }
};