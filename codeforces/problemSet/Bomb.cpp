#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


 int maxSum(vector<int>& a, vector<int>& b,int k, long long sum){
    if (k==0)
    {
 return sum;
    }
    int maxOfA=*max_element(a.begin(), a.end());
    
    vector<int>::iterator it;
   it= find(a.begin(), a.end(), maxOfA); 

    int index=distance(a.begin(),it);
  int  maxVal=max(0,a[index]-b[index]);

    a[index]=maxVal;
    sum=1LL*sum+1LL*maxOfA;
maxSum(a,b,k-1,sum);
}


int main(){
vector<int> a={1000000};
vector<int> b={1};
cout<<maxSum(a,b,10000,0);
return 0;
}