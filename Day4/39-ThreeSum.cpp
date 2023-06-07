#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	// Write your code here.
	// set<vector<int>>us;
        // for(int i=0;i<nums.size();i++){
        //     unordered_set<int>temp;
        //     for(int j=i+1;j<nums.size();j++){
        //         int third=-1*(nums[i]+nums[j]);
        //         if(temp.find(third)!=temp.end()){
        //            vector<int> t={nums[i],nums[j],third};
        //             sort(t.begin(),t.end());
        //             us.insert(t);
        //         }
        //         temp.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>>ans(us.begin(),us.end());
        // return ans;
        //This hashset approach understood from the striver got failed for the last three test cases.
        //Using the two pointer approach on the sorted array-
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];
                if(temp<K)j++;
                else if(temp>K)k--;
                else{
                    vector<int>t={nums[i],nums[j],nums[k]};
                    ans.push_back(t);
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1])j++;
                    while(j<k&&nums[k]==nums[k+1])k--;
                }
            }
        }
        return ans;
}
