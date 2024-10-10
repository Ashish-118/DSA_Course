#include<iostream>
#include<vector>
using namespace std;

void reverse_after(vector<int> &data,int m){

reverse(data.begin()+m+1,data. end());

}
void display(vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
}



int main(){
vector<int> arr;
arr.push_back(2);
arr.push_back(4);
arr.push_back(1);
arr.push_back(6);
arr.push_back(9);
arr.push_back(66);
arr.push_back(8);
int m=3;

reverse_after(arr,m);
display(arr);
return 0;
}