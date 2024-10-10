#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0){
            swap(nums[j], nums[i]);
        i++;
    }
    }
}

void display(vector<int> &nums)
{
    for (int i = 0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{

vector<int> arr;
arr.push_back(0);
arr.push_back(1);
arr.push_back(0);
arr.push_back(3);
arr.push_back(12);

moveZeroes(arr);
display(arr);
    return 0;
}