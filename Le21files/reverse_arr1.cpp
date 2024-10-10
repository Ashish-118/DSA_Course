#include <iostream>
#include <vector>
using namespace std;
vector<int> reverse(vector<int> &v, int m)
{
    int s = m+1, e = v.size() - 1;
    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}
void display(vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
}
using namespace std;

int main()
{
    vector<int> arr;
    int m=3;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(9);
    arr.push_back(66);
    arr.push_back(8);

    vector<int> ans= reverse(arr,m);
    display(ans);

    return 0;
}