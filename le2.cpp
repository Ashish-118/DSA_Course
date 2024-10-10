#include<iostream>
using namespace std;

int main(){
    // unsigned int num=500;
    unsigned int num=-500;// will cause an interal error as unsigned stores positive number only
    cout<<num;
    return 0;
}