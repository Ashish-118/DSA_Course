#include <bits/stdc++.h>
using namespace std;

void MaxOdd_MinEven(vector<long long int> arr, int &index_max_odd, int &index_min_even, long long int &min_even_val, long long int &max_odd_val)
{

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            if (arr[i] < min_even_val)
            {
                min_even_val = arr[i];
                index_min_even = i;
            }
        }
        else
        {
            if (arr[i] > max_odd_val)
            {
                max_odd_val = arr[i];
                index_max_odd = i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int user;
        vector<long long int> arr;
        for (int i = 0; i < n; i++)
        {
            cin >> user;
            arr.push_back(user);
        }

        bool odd = false, even = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & 1)
            {
                odd = true;
            }
            // if (arr[i]% 2 == 0)
            else
            {
                even = true;
            }
        }
        int count=0;
        if (odd && even)
        {

            bool loop_controller = true;
            while (loop_controller)
            {
                int indexOfmaxOdd = 0;
                int indexOfminEven = 0;
                long long int max_odd_Val = INT_MIN;
                long long int min_even_Val = __INT64_MAX__;

                MaxOdd_MinEven(arr, indexOfmaxOdd, indexOfminEven, min_even_Val, max_odd_Val);
                if (min_even_Val == __INT64_MAX__ )
                {
                    break;
                }

                if (max_odd_Val > min_even_Val)
                {
                    arr[indexOfminEven] = arr[indexOfmaxOdd] + arr[indexOfminEven];
                    count++;
                }
                else
                {
                    arr[indexOfmaxOdd] = arr[indexOfmaxOdd] + arr[indexOfminEven];
                    count++;
                }
            }
        }

        cout<<count<<endl;
    }

    return 0;
}