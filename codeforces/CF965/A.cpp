// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

void solve(int index, vector<int> nums, vector<int>& output, int k,int check)
{
    // cout<<"hello"<<endl;
    if (index >= nums.size())
    {
        if (output.size() == k)
        {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum==check)
            {
                for (int i = 0; i < output.size(); i++)
                {
                 cout<<output[i]<<" ";
                }
                cout<<endl;
               return;
            }
            
            
        }

        return;
    }

    // exclude
    solve(index + 1, nums, output, k,check);

    // include
    int val = nums[index];
    output.push_back(val);
    solve(index + 1, nums, output,k,check);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> arr;
    for (int i = 0; i < 2000; i++)
    {
        arr.push_back(i);
    }
    for (int i = 1; i < 2000; i++)
    {
        arr.push_back(-i);
    }

    while (t--)
    {
        int x,y,k;
        cin>>x>>y>>k;
        vector<int> output;
        solve(0,arr,output,k,x);

        

    }
    return 0;
}