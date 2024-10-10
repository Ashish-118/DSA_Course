#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &data, int k)
{
   
vector<int> temp(data.size());
for (int i = 0; i < data.size(); i++)
{
    temp[(i+k)%data.size()]=data[i];// concept used: (whatever)%n = {0 - - - -(n-1)}
}

data=temp;


}


void display(vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(9);
    v.push_back(11);
    v.push_back(3);
    v.push_back(16);
int k=2;
    rotate(v,k);
    display(v);
    return 0;
}