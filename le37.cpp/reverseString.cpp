#include<iostream>
using namespace std;

void reverse(string& word,int s){
    int len=word.length()/2;
    if (s==len)
    {
     return ;
    }
    swap(word[s],word[len*2-1-s]);
    return reverse(word,s+1);
    
}


int main(){
string word="Ashish";
reverse(word,0);
cout<<word;
return 0;
}