#include <bits/stdc++.h> 

void Solve(stack<int>&inputStack,int size, int count){
  if (count == size / 2) {
    inputStack.pop();
    return;
  }

  int top = inputStack.top();
  inputStack.pop();
  Solve(inputStack,size,count+1);
  inputStack.push(top);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
     Solve(inputStack,N,0);
   
}