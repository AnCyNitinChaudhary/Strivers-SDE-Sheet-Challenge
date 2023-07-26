#include<bits/stdc++.h>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	vector<int>ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<queries.size();i++){
		int maxi=-1;
		int j=0;
		while(j<arr.size()&&arr[j]<=queries[i][1]){
			maxi=max(maxi,queries[i][0]^arr[j]);
			j++;
		}
		ans.push_back(maxi);
	}
	return ans;
}
