#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxAns(string s, int n)
{


   
    int count = 1;
    int max = 0;
    int prev = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int charindex = s[i] - 'A';

        if (prev != charindex)
        {
            count = 1;
        }

        if ((0 <= charindex && charindex< 4) && count <= n)
        {
            count++;
            max++;
        }
        prev = charindex;
   
    }

    return max;
}
int main()
{
    int t;
    cin >> t;
    if (1 <= t && t<=1000)
    {
        for (int i = 0; i < t; i++)
        {
            int n;
            cin >> n;
            string s="";
            char a[400];
            for (int j = 0; j < (4*n); j++)
            {
                cin>>a[j];
                s.push_back(a[j]);
            }
            
            sort(s.begin(), s.end());
           cout<< maxAns(s,n)<<endl;
        }
    }

    return 0;
}