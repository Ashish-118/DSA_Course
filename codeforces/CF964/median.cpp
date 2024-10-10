// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int index, vector<int> nums, vector<int> output, long long int &sum, int k, int s, int e, long long int m)
{
    if (index >= nums.size())
    {
        if (output.size() == k)
        {
            sort(output.begin(), output.end());
            int mid = s + (e - s) / 2;
            int median = output[mid];
            sum = (1LL * sum % m + 1LL * median % m) % m;
            // cout<<"sum "<<sum<<endl;
        }

        return;
    }

    // exclude
    solve(index + 1, nums, output, sum, k, s, e, m);

    // include
    int val = nums[index];
    output.push_back(val);
    solve(index + 1, nums, output, sum, k, s, e, m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--)
    {

        int k, n;
        cin >> n >> k;
        vector<int> digits;
        int user;
        for (int i = 0; i < n; i++)
        {
            cin >> user;
            digits.push_back(user);
        }
        vector<int> output;
        long long int sum = 0;
        long long int m = (pow(10, 9)) + 7;
        solve(0, digits, output, sum, k, 0, k - 1, m);
        cout << 1LL * sum << endl;
    }
    return 0;
}