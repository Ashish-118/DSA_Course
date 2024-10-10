#include<iostream>

using namespace std;

bool isPossible(int data[], int n, int m, int mid){
int sum=0;
int student_number=1;
for (int i = 0; i<n; i++)
{
    if (sum+data[i]<=mid)
    {
    sum+=data[i];
    }
    else
    {
        student_number++;
        sum=data[i];
        if (student_number>m || sum>mid)
        {
          return false;
        }
      
    }
    
}
    return true;

}

int bookAllocation(int data[], int n, int m){
int s=0;
int e=0;
int ans=-1;
int mid=s+(e-s)/2;
for (int i = 0; i < n; i++)
{
    e+=data[i];
}
while (s<=e)
{
bool c=isPossible(data, n,  m, mid);   
if (c)
{
    ans=mid;
    e=mid-1;
}
else{
    s=mid+1;
}
mid=s+(e-s)/2;
}

return ans;

}

int main(){
int n=4, m=4;
int page[]={5,17,100,11};
cout<<bookAllocation(page,n,m)<<endl;
return 0;
}