#include <bits/stdc++.h> 
//  void f(string&nums,vector<string>&ans,string&temp,unordered_map<char,int>&um){
//         if(temp.size()==nums.size()){
//             ans.push_back(temp);
//             return;
//         }
//         for(int i=0;i<nums.size();i++ ){
//             if(um[nums[i]]>0){
//                 temp.push_back(nums[i]);
//                 um[nums[i]]--;
//                 f(nums,ans,temp,um);
//                 temp.pop_back();
//                 um[nums[i]]++;
//             }
//         }
//     }
//This solution is giving some error and I am not able to find that error.


//The below is the implementation of swapping based approach which does not take any extra space and solve this efficiently and generate the required answer.
  void f(int i,string &nums,vector<string> &ans){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int index=i;index<nums.size();index++){
            swap(nums[index],nums[i]);
            f(i+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
vector<string> findPermutations(string &s) {
    // Write your code here.
        // vector<string>ans;
        // string temp;
        // int n=s.size();
        // unordered_map<char,int>um;
        // for(int i=0;i<s.size();i++)um[s[i]]++;
        // f(s,ans,temp,um);
        // return ans;
        //Some error is coming in this appraoch
        vector<string>ans;
        f(0,s,ans);
        return ans;
}
