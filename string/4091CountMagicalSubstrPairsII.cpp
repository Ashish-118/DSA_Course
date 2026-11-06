class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();

        vector<vector<int>>pre(n, vector<int>(26, -1));
        for(int i=0;i<n;i++) {
            if(i > 0) {
                pre[i] = pre[i-1];
            }
            pre[i][s[i]-'a'] = i;
        }

        vector<vector<int>>suf(n, vector<int>(26, n));
        for(int i=n-1;i>=0;i--) {
            if(i+1 < n) {
                suf[i] = suf[i+1];
            }
            suf[i][s[i]-'a'] = i;
        }

        long long ans = 0;
        for(int m=0;m+1<n;m++) {
            int i = m, j = m+1;
            vector<bool>vis_i(26), vis_j(26);

            while(i >= 0 and j < n) {
                vis_i[s[i]-'a'] = vis_j[s[j]-'a'] = true;
                
                int ii = -1;
                for(int t=0;t<26;t++) {
                    if(!vis_i[t]) {
                        ii = max(ii, pre[i][t]);
                    }
                }

                int jj = n;
                for(int t=0;t<26;t++) {
                    if(!vis_j[t]) {
                        jj = min(jj, suf[j][t]);
                    }
                }

                ans += 1LL*(i-ii)*(jj-j);
                i = ii;
                j = jj;
            }
        }

        return ans;
    }
};