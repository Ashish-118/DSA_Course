#include<iostream>
using namespace std;


int main(){
int n;
cin>>n;
string user;
int x=0;
for (int i = 0; i < n; i++)
{
    cin>>user;
    if (user=="--X" || user=="X--")
    {
        x--;
    }
    else{
        x++;
    }
}
cout<<x<<endl;
return 0;
}