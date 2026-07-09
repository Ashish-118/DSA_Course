

class Solution {
public:
    vector<int> rank, parent;

    int find_parent(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = find_parent(parent[node]);
    }

    void unionByRank(int parentU, int parentV) {
        if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        } else if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        } else {
            parent[parentU] = parentV;
            rank[parentV]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        rank.assign(n, 0);
        parent.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int prev = -1;

        for (int i = 0; i < n; i++) {

            int idx = upper_bound(begin(nums), end(nums), nums[i] + maxDiff) -
                      begin(nums) - 1;

            if (idx <= prev)
                continue;

            int l = prev + 1, r = idx;

          

            for (int j = l; j <= r; j++) {
                int parentU = find_parent(i);
                int parentV = find_parent(j);

                if (parentU != parentV) {
                    unionByRank(parentU, parentV);
                }
            }

            prev = idx;
        }

        for (int i = 0; i < n; i++) {
            find_parent(i);
        }

        vector<bool> ans(queries.size(), false);
        int i = 0;

        for (auto q : queries) {
            int parentU = find_parent(q[0]);

            int parentV = find_parent(q[1]);

            if (parentU == parentV) {
                ans[i] = true;
            }
            i++;
        }

        return ans;
    }
};
