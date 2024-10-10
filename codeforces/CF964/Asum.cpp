#include <bits/stdc++.h>
using namespace std;



int sum(int n){

    if (n==0)
    {
     return 0;
    }
    
    int remainder=n%10;


    return remainder+sum(n/10);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin>>n;

         cout<<sum(n)<<endl;
        

    }
        return 0;
}