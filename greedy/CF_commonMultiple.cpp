#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;

        unordered_set<int> st;
        int countUnique=0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (st.find(x) == st.end())
            {
                st.insert(x);
                countUnique++;
            }
        }

        cout<<countUnique<<endl;
    }
    return 0;
}