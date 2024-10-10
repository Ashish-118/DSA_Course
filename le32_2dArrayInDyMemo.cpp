#include<iostream>
using namespace std;


int main(){
   // This Array is created in Heap
int row,col;
cin>>row>>col;

int** arr=new int*[row];
for (int i = 0; i < row; i++)
{
    arr[i]=new int[col];
}

for (int i = 0; i < row; i++)
{
   for (int j = 0; j < col; j++)
   {
   cin>>arr[i][j];
   }
   
}
for (int i = 0; i < row; i++)
{
   for (int j = 0; j < col; j++)
   {
   cout<<arr[i][j]<<" ";
   }
   
}


return 0;
}