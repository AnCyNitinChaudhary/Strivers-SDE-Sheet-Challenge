#include <bits/stdc++.h>
// void f(int i,vector<int>&nums,set<vector<int>>&us,vector<int>&temp){
//         if(i<0){
//             sort(temp.begin(),temp.end());
//             us.insert(temp);
//             return;
//         }
//         f(i-1,nums,us,temp);
//         if (nums[i] != nums[i - 1]) {
//           temp.push_back(nums[i]);
//           f(i - 1, nums, us, temp);
//           temp.pop_back();
//         }
//     } 
// vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
// {
//         set<vector<int>>us;
//         vector<int>temp;
//         sort(nums.begin(),nums.end());
//         f(n-1,nums,us,temp);
//         vector<vector<int>>ans(us.begin(),us.end());
//         // sort(ans.begin(),ans.end());
//         return ans;
//     // Write your code here.
// }
//The above code is working fine on leetcode but it's not working properly here on coding ninjas.

void rec(int st,vector<int> &cur, vector<int> &arr, vector<vector<int>> &subsets){

    subsets.push_back(cur);

    for(int i = st; i < arr.size(); i++){
        
        if (i==st or arr[i] != arr[i-1]){

            cur.push_back(arr[i]);
            rec(i+1, cur, arr, subsets);
            cur.pop_back();
        }
    }

}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> subsets;
    sort(arr.begin(), arr.end());
    vector<int> cur;
    rec(0, cur, arr, subsets);

    return subsets;
}
