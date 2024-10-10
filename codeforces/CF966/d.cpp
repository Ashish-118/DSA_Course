#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int noOfInputsLoops;

    cin >> noOfInputsLoops;
    while (noOfInputsLoops--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        string s;
        cin >> s;

        int start = 0, end = n - 1;
        int sum = 0;

        vector<int> difference_array(n + 1, 0);
       
        while (start < end)
        {

            if (s[start] != 'L' || s[end] != 'R')
            {
                if (s[start] != 'L')
                {
                    start++;
                }
                if (s[end] != 'R')
                {
                    end--;
                }
            }
            else
            {

                difference_array[start++]++;
                difference_array[end--+1]--;
            }
        }

        for (int i = 1; i < n; i++)
        {
            difference_array[i]+=difference_array[i-1];
        }
        for (int i = 0; i < n; i++)
        {
            sum += arr[i] * difference_array[i];

        }

        cout << sum << endl;
    }
    return 0;
}