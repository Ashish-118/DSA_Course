#include<iostream>
using namespace std;

int& set(int a){// will throw an error as It is a Bad practise  
                // REASON:
                // 1. The variables here formed inside  the function is local and it will be destroyed once we 
                //    go out of the function block,  so if variables will be destroyed then we cannot acess any memory.
                // 2. manlo kisi aur ne change kardiya ho
    int num=a;
    int& ans=num;
    return ans;
}

int main(){
int n=5;
cout<<set(n)<<endl;
return 0;
}