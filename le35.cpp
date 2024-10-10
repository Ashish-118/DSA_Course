#include<iostream>
using namespace std;

// int printnum(int n){
//     string name[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
//     int digit=n%10;
//     cout<<name[digit]<<" ";
//     if (n<10)
//     {
//    return 0;
//     }
    
//     return printnum(n/10);
// }// this is tail recurssion  so it will  print in reverse order so

int printnum(int n){
    string name[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
    int digit=n%10;
    if (n==0)
    {
   return 0;
    }
     printnum(n/10);
    cout<<name[digit]<<" ";
}

int main(){
printnum(412);
return 0;
}