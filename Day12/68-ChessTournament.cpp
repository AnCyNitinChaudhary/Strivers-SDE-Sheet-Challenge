#include <bits/stdc++.h>
int answer=INT_MIN;
// int findmin(vector<int>&answerVector,int c){
// 	sort(answerVector.begin(),answerVector.end());
// 	int temp=INT_MIN;
// 	for(int i=0;i<c;i++){
// 		if(answerVector[i]<temp)temp=answerVector[i];
// 	}
// 	return temp;
// }
// void solve(vector<int>&positions,int index,int c,vector<int>&answerVector){
// 	if(answerVector.size()>c)return;
// 	if(index<0){
// 		if(answerVector.size()==c)answer=max(answer,findmin(answerVector,c));
// 	}
// 	//notTake
// 	solve(positions,index-1,c,answerVector);
// 	//Take
// 	answerVector.push_back(positions[index]);
// 	solve(positions,index-1,c,answerVector);
// 	//answerVector.pop_back();
// }
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	//As per my understanding, I can use Dynamic Programming to sovle this problem.
	//I can do all possible combinations and when my answer vector will be having the required amount of elements then I will storing answer=min(answer,findmin(answerVector));
	// vector<int>answerVector;
	// solve(positions,n-1,c,answerVector);
	// return answer;


	//This problem is based on binary Search on answer.
	//Solvig using BS-

	sort(positions.begin(),positions.end());   
	int ans=0 , l=1 , r = positions[n-1]; 
	while(l<=r)
    { 
		int mid=(l+r)/2; 
        int count=1 , previousRoom=positions[0]; 
		for(int i = 1 ; i < n ; i++) 
        {
			if(positions[i]-previousRoom >= mid) 
            {  
				count++;
				previousRoom=positions[i];
			}
		}
		if(count >= c)
        { 
			ans=mid;
			l=mid+1;
		}
		else 
        {  
			r=mid-1;
		}
	}
 
	return ans;
}
