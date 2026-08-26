#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    set<int> st;
    vector<int> a(n);

    vector<bool> sieve(101, true);
  

    for(int i=0; i<n; i++){
        cin>>a[i];
        st.insert(a[i]);
        
    }

    int count=0;

    for(auto x:st){
        if(!sieve[x]) continue;

        count++;

        for(int j=x+x; j<=100; j+=x){
            sieve[j] = false;
        }

    }


    cout<<count<<endl;



   
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
        solve();
    
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'

// void solve() {
//     int n;
//     cin>>n;
//     // unordered_set<int> st;
//     vector<int> a(n);
//     vector<bool> visited(n,false);

//     // vector<bool> sieve(101, true);
//     // sieve[0] = sieve[1] = false;

//     for(int i=0; i<n; i++){
//         cin>>a[i];
        
//     }

//     int count=0;

//     sort(a.begin(), a.end());

//     for(int i=0; i<n; i++){
//         if(visited[i]) continue;
//         count++;
//         for(int j=i+1; j<n; j++){
//             if(gcd(a[i],a[j])==a[i]){
//                 visited[j]=true;
//             }
//         }
//     }

//     cout<<count<<endl;



   
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
   
//         solve();
    
//     return 0;
// }