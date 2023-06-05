#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
//Using the concept of hashing.
unordered_map<long long,int>um;
long long sum=0;
int ans=0;
for(int i=0;i<arr.size();i++){
  sum+=arr[i];
if(sum==0){
  ans=max(ans,i+1);
}
if (um.find(sum) != um.end()) {
  ans = max(ans, i - um[sum]);
}
else um[sum] = i;
}
return ans;
  // Write your code here
}
