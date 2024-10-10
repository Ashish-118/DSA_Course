#include<iostream>
using namespace std;


int main(){
int arr[14]={8,9,8,7,6,5,4,7,4,6,6,6,8,9};
for (int i = 0; i < 7; i++)
{
 for (int j = 0; j < 14-i; j++)
 {
    if (arr[j]>arr[j+1])
    {
      swap(arr[j],arr[j+1]);
    }
    
 }
}

for (int i = 0; i < 14; i++)
{
cout<<arr[i]<<" ";
}

return 0;
}