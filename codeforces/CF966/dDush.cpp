#include <bits/stdc++.h>
using namespace std;

int main()
{
    int noOfInputsLoops, n;
    cin >> noOfInputsLoops;
    while (noOfInputsLoops--)
    {
        cin >> n;
        vector<int> input(n);
        long long sum = 0;
        vector<long long> prefixSum(n);
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
            sum += input[i];
            prefixSum[i] = sum;
        }
        string s;
        cin >> s;

        int left = 0;
        int right = n - 1;
        long long output = 0;

        while (left < right)
        {
            while (left < right && s[left] != 'L')
            {
                left++;
            }
            while (left < right && s[right] != 'R')
            {
                right--;
            }
            if (left < right)
            {
                long long temp;
                if (left > 0)
                {
                    temp = prefixSum[right] - prefixSum[left - 1];
                }
                else
                {
                    temp = prefixSum[right];
                }
                output += temp;
                left++;
                right--;
            }
        }
        cout << output << endl;
    }
}
