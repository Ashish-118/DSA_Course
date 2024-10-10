#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int count = 0;
        if (a > c && b > d)
        {
            count++;
        }
        if (a > d && b > c)
        {
            count++;
        }
        if (b > c && a > d)
        {
            count++;
        }
        if (b > d && a > c)
        {
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}