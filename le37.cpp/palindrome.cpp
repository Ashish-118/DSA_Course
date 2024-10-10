#include<iostream>
using namespace std;

bool palindrome(string word, int s){
    int len=word.length();
    if (s==(len/2))
    {
 return true;
    }
    if(word[s]==word[len-1-s]){
        return palindrome(word,s+1);
    }
    else{
        return false;
    }
    
}

int main(){
    string word="abccba";
cout<<endl<<palindrome(word,0)<<endl;
return 0;
}