class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions,
                                      vector<int> &healths, string directions)
    {
        int left = -1;

        int n = positions.size();

        vector<pair<int, int>> robotPos;

        for (int i = 0; i < n; i++)
        {
            robotPos.push_back({positions[i], i});
        }

        sort(begin(robotPos), end(robotPos));

        for (int i = 0; i < n; i++)
        {
            if (left == -1)
            {
                left = i;
                continue;
            }
            else if (healths[robotPos[left].second] == INT_MIN)
            {

                while (left >= 0 && healths[robotPos[left].second] == INT_MIN)
                {
                    left--;
                }
                if (left < 0)
                    left = i;
            }

            int leftIdx = robotPos[left].second;
            int rightIdx = robotPos[i].second;

            if (directions[leftIdx] == 'R' && directions[rightIdx] == 'L')
            {
                if (healths[leftIdx] == healths[rightIdx])
                {
                    healths[leftIdx] = INT_MIN;
                    healths[rightIdx] = INT_MIN;
                    left--;
                }
                else if (healths[leftIdx] > healths[rightIdx])
                {
                    healths[leftIdx]--;
                    healths[rightIdx] = INT_MIN;
                }
                else
                {
                    healths[leftIdx] = INT_MIN;
                    healths[rightIdx]--;
                    left--;
                    i--;
                }
            }
            else
            {
                left = i;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (healths[i] != INT_MIN)
            {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};