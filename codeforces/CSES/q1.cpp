#include <bits/stdc++.h>
using namespace std;

int main()
{

        int n;
        cin >> n;
        vector<int> arr(n);
        map<int,int> mapNum;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mapNum[arr[i]]++;
        }

        cout<<mapNum.size()<<endl;



    return 0;
}