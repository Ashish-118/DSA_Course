#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> req_days;
    int user;
    for (int i = 0; i < n; i++)
    {
        cin >> user;
        req_days.push_back(user);
    }
    vector<int> temp(req_days);
    vector<int> indices;
    sort(temp.begin(), temp.end());
    int sum = 0,cnt=0;

    for (int i = 0; i < n; i++)
    {
        if (sum + temp[i] <= k)
        {
            vector<int>::iterator it;
            it = find(req_days.begin(), req_days.end(), temp[i]);
            int index = distance(req_days.begin(), it);
            req_days[index]=-1;
            indices.push_back(index);
          
            sum += temp[i];
            cnt++;
        }
    }
cout<<cnt<<endl;
for (int i = 0; i < indices.size(); i++)
{
    cout<<indices[i]+1<<" ";
}

    return 0;
}