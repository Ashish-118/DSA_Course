#include <bits/stdc++.h>

void sort_recur(stack<int> &s, int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	
    if(x>=s.top()){
		s.push(x);
		return;
	}

	int num=s.top();
	s.pop();
	sort_recur(s,x);
	s.push(num);
	

}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;

	}

	int top=stack.top();
	stack.pop();

	sortStack(stack);
	sort_recur(stack,top);
	// stack.push(top);
}