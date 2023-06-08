#include <bits/stdc++.h> 
// unordered_set<int>us;
// int f(vector<int>&nums,int i){
//     if(i<0)return 0;
//     int take=nums[i]+f(nums,i-1);
//     int nottake=f(nums,i-1);
//     us.insert(take);
//     us.insert(nottake);
//     return 0;
// }


void fun(int i,vector<int>&num,vector<int>&ans,int sum){
    if(i<0){
        ans.push_back(sum);
        return;
    }
    fun(i-1,num,ans,num[i]+sum);
    fun(i-1,num,ans,sum);
}
vector<int> subsetSum(vector<int> &num)
{
    // int temp=f(num,num.size()-1);
    // vector<int>ans(us.begin(),us.end());
    // sort(ans.begin(),ans.end());
    // return ans;
    // Write your code here.
    vector<int>ans;
    fun(num.size()-1,num,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}
