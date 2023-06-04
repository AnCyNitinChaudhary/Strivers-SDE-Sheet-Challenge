#include <bits/stdc++.h>
#define lint long long
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	//Observation-
	/*
	realSum=idealSum-M+R
	or
	idealSum-realSum=M-R....................1
	Similarly-
	idealSumSquares-realSumSquares=M^2-R^2...........2
	So, We can easily obtain M and R using both 1 and 2 equations.

	 */
	//  lint idealSum=(n*(n+1))/2;
	//  lint idealSumSquares=(n*(n+1)*(2*n+1))/6;
	//  lint realSum=0;
	//  lint realSumSquares=0;
	//  for(int i=0;i<n;i++){
	// 	 realSum+=arr[i];
	// 	 realSumSquares+=((lint)arr[i]*(lint)arr[i]);
	//  }
	//  lint x=idealSum-realSum;
	//  lint y=(idealSumSquares-realSumSquares)/x;
	//  lint M=(x+y)/2;
	//  lint R=(y-x)/2;
	// // lint R=M-x;
	//  return {(int)M,(int)R};
	 //The above approach is failinig on last two test cases but I don't know why this is happening.
	//now solving by bruteforce-
	sort(arr.begin(),arr.end());
	int R;
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]){
			R=arr[i];
			break;
		}
	}
	 int idealSum=(n*(n+1))/2;
	 int realSum=0;
	 for(int i=0;i<n;i++){
		 realSum+=arr[i];
	 }
	 int M=idealSum-realSum+R;
	 return {M,R};
}
