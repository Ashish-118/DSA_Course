class Solution {
public:
    int mod = 1000000007;
    vector<vector<int>> t;

    int l;

    int modPow(int a, int b) {
        if (b < 0)
            return 0;
        int ans = 1;

        while (b != 0) {
            if (b & 1) {
                ans = (1LL * ans * a) % mod;
            }

            a = (1LL * a * a) % mod;

            b >>= 1;
        }

        return ans;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int maxiNode = -1;
        for (auto e : edges) {
            maxiNode = max(maxiNode, e[0]);
            maxiNode = max(maxiNode, e[1]);
        }

        l = log2(maxiNode) + 1;

        t.assign(maxiNode + 1, vector<int>(l, -1));

        for (auto e : edges) {
            t[e[1]][0] = e[0];
        }

        for (int i = 1; i < l; i++) {
            for (int node = 1; node <= maxiNode; node++) {

                if (t[node][i - 1] != -1)
                    t[node][i] = t[t[node][i - 1]][i - 1];
            }
        }

        vector<int> ans;
        cout << "l " << l << endl;

        for (auto q : queries) {

            int d1 = 0, d2 = 0;
            int curr = q[0];
            for (int i = l - 1; i >= 0; i--) {
                if (t[curr][i] != -1) {
                    curr = t[curr][i];
                    d1 += (1 << i);
                }
            }
            curr = q[1];
            for (int i = l - 1; i >= 0; i--) {

                if (t[curr][i] != -1) {
                    curr = t[curr][i];
                    d2 += (1 << i);
                }
            }

            int depth = abs(d1 - d2);

            if (d1 >= d2) {
                int jumps = d1 - d2;
                int curr1 = q[0];
                int curr2 = q[1];
                for (int i = 0; i < 32; i++) {
                    if (jumps & (1 << i)) {
                        curr1 = t[curr1][i];
                    }
                }

                for (int i = l - 1; i >= 0; i--) {
                    if (t[curr1][i] != t[curr2][i]) {
                        curr1 = t[curr1][i];
                        curr2 = t[curr2][i];
                        depth += 2 * (1 << i);
                    }
                }

                if (curr1 != curr2) {
                    depth += 2;
                }

            } else {
                int jumps = d2 - d1;
                int curr1 = q[0];
                int curr2 = q[1];
                for (int i = 0; i < 32; i++) {
                    if (jumps & (1 << i)) {
                        curr2 = t[curr2][i];
                    }
                }
                for (int i = l - 1; i >= 0; i--) {
                    if (t[curr1][i] != t[curr2][i]) {
                        curr1 = t[curr1][i];
                        curr2 = t[curr2][i];
                        depth += 2 * (1 << i);
                    }
                }

                if (curr1 != curr2) {
                    depth += 2;
                }
            }

            ans.push_back(modPow(2, depth - 1));
        }

        return ans;
    }
};