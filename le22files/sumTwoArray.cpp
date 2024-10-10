#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
}
void findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int vall = a[i];
        int val2 = b[j];
        int sum = vall + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    // first case
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while (j >= 0)
    {
        int sum = b[j] + carry;
    
        carry = sum/10;

        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    if (carry!= 0)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    display(ans);
}
int main()
{
    vector<int> v1, v2;
    v1.push_back(9);
    v1.push_back(8);

    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(4);

    findArraySum(v1, 2, v2, 3);

    return 0;
}