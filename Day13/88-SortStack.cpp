#include <bits/stdc++.h> 
// void sortStack(stack<int> &st)
// {
// 	if(st.empty())return;
// 	int t=st.top();
// 	st.pop();
// 	int stop=INT_MIN;
// 	if(!st.empty()){
// 		stop=st.top();
// 		st.pop();
// 	}
// 	sortStack(st);
// 	if(t>stop){
// 		st.push(t);
// 		if(stop!=INT_MIN)st.push(stop);
// 	}
// 	else {
// 		st.push(stop);
// 		if(t!=INT_MIN)st.push(t);
// 	}
// 	return;
// 	// Write your code here
// }

void sortedInsert(stack<int> &stack, int current)
{
	if (stack.empty() || current > stack.top())
	{
		stack.push(current);
		return;
	}
	int top = stack.top();
	stack.pop();
	sortedInsert(stack, current);
	stack.push(top);
}
void sortStack(stack<int> &stack)
{
	if (stack.empty())
	{
		return;
	}
	int top = stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack, top);
}
