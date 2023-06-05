#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    // Write your code here.
        sort(nums.begin(),nums.end());
        int ans=1;
        int curCount=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)curCount++;
            else if(nums[i]!=nums[i-1]) curCount=1;
            ans=max(ans,curCount);
        }
        return ans;
}
