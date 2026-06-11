class Solution
{
public:
    using p = pair<int, pair<int, int>>;
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        vector<vector<int>> ans;

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        map<pair<int, int>, bool> visited;
        visited[{0, 0}] = true;
        int n = nums1.size();
        int m = nums2.size();

        while (k--)
        {
            auto front = pq.top().second;
            pq.pop();
            int i = front.first;
            int j = front.second;
            ans.push_back({nums1[i], nums2[j]});
            int i2 = (i + 1) % n;
            int j2 = (j + 1) % m;

            if (visited[{i, j2}] == false)
            {
                pq.push({nums1[i] + nums2[j2], {i, j2}});
                visited[{i, j2}] = true;
            }
            if (visited[{i2, j}] == false)
            {
                pq.push({nums1[i2] + nums2[j], {i2, j}});
                visited[{i2, j}] = true;
            }
            if (visited[{i2, j2}] == false)
            {
                pq.push({nums1[i2] + nums2[j2], {i2, j2}});
                visited[{i2, j2}] = true;
            }
        }

        return ans;
    }
};
// T.C : O(k log k)
// S.C : O(k)