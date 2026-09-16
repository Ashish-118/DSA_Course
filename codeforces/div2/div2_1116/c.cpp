#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<bool> hasPotato(n,false);
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                hasPotato[i]=true;  
            }   
        }

        for(int i=0; i<n; i++){

            if(visited[i]) continue;

           
            if (!hasPotato[(i + 1) % n])
            {
                swap(s[i], s[(i + 1) % n]);
                visited[(i + 1) % n] = true;
            }

        }

        int score_red=0, score_blue=0;

        for(int i=0; i<n; i++){
            if(i&1){
                if(s[i]=='1') score_blue++;
            }
            else{
                if(s[i]=='1') score_red++;
            }
        }
        cout << score_red << " " << score_blue << endl;
    }

    return 0;
}