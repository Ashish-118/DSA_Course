class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<pair<int, int>> st;
        st.insert({0, 50001});

        unordered_map<int, int> mp;

        auto cmp = [&](const pair<int, int>& mid, int tar) {
            return mid.second < tar;
        };

        vector<bool> ans;

        for (auto q : queries) {
            int type = q[0];
            if (type == 1) {
                auto lb = lower_bound(begin(st), end(st), q[1], cmp);
                if (lb != st.end()) {
                    auto p = *lb;
                    st.erase(lb);
                    st.insert({p.first, q[1]});
                    st.insert({q[1], p.second});
                    mp[q[1]] = max(mp[p.first], q[1] - p.first);
                    mp[p.second] = max(mp[q[1]], p.second - q[1]);
                    auto it=st.find({q[1],p.second});
                    int maxi=mp[p.second];
                    it++;

                    while(it!=st.end()){
                        maxi=max(maxi,it->second-it->first);
                        mp[it->second]=maxi;
                        it++;
                    }
                }

            } else {
              auto lb = lower_bound(begin(st), end(st), q[1], cmp);
                if (lb != st.end()) {
                  int maxBlock = max(mp[lb->first], q[1] - lb->first);
                  cout<<maxBlock<<endl;
                    if (maxBlock >= q[2]) {
                        ans.push_back(true);
                    } else {
                        ans.push_back(false);
                    }
                }
            }

            for(auto s:st){
                cout<<s.first<<" "<<s.second<<endl;
            }
        }

        return ans;
    }
};