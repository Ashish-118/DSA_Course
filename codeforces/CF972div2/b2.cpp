#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> teacher(m);
        for (int i = 0; i < m; i++)
        {
            cin >> teacher[i];
        }
        sort(teacher.begin(), teacher.end());

        
        vector<int> query(q);

        for (int i = 0; i < q; i++){
            cin >> query[i];
            
            int s=0,e=m-1;
            int mid=s+(e-s)/2;
            while(s<=e){
                if(mid!=0 && query[i]<=teacher[mid] && query[i]>=teacher[mid-1]){
                    int mini=min(abs(query[i]-teacher[mid]),abs(query[i]-teacher[mid-1]));
                    cout<<mini<<endl;
                 
                    break;
                }
                else if(query[i]>teacher[mid]){
                  

                    s=mid+1;
                }
                else{
                   
                    e=mid-1;
                }
                mid=s+(e-s)/2;
            }
   

            if(s>e && s==0){
      
                cout<<abs(teacher[s]-1)<<endl;
            }
            else if(s>e && e==m-1){
              
                cout<<abs(teacher[e]-n)<<endl;
            }
        }
    }
    return 0;
}