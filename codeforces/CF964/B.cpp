#include <bits/stdc++.h>
using namespace std;



int score(int a ,int b){
if (a>b)
{
    return 1;
}
else if (a==b)
{
   return 0;
}
else
{
    return -1;
}
}
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int count = 0;
        if ((score(a,c)+score(b,d))>0)
        {
            count++;
        }
        if ((score(a,d)+score(b,c))>0)
        {
            count++;
        }
        if ((score(b,c)+score(a,d))>0)
        {
            count++;
        }
        if ((score(b,d)+score(a,c))>0)
        {
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}