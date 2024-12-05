#include<iostream>
using namespace std;

int power(int n, int raiseto){
    if (raiseto==0)
    {
  return 1;
    }
    if (raiseto%2==0)
    {
   return power(n,raiseto/2)*power(n,raiseto/2);
    }
    else{
        return n*power(n,raiseto-1);
    }
    
    
}

int main(){
cout<<endl<<"The answer is "<<power(2,10)<<endl;
return 0;
}