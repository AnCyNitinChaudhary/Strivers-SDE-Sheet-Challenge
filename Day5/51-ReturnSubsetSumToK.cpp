  #include<bits/stdc++.h>
//     void f(int i,vector<int>&candidates,int target,set<vector<int>>&ans,vector<int>&temp,int sum){
//         if(sum==target){
//             ans.insert(temp);
//             //return;
//         }
//         if(i>=candidates.size())return;
//         //Not take
//         f(i+1,candidates,target,ans,temp,sum);
//         //take
//         temp.push_back(candidates[i]);
//         f(i+1,candidates,target,ans,temp,sum+candidates[i]);
//         temp.pop_back();
//     }
// vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
// {
//         set<vector<int>>ans;
//         vector<int>temp;
//         int sum=0;
//         f(0,arr,k,ans,temp,sum);
//         vector<vector<int>>answer(ans.begin(),ans.end());
//         return answer;
//     // Write your code here.
// }
//I have solved this question and passed 7 test cases out of 8.Feeling proud.

void findSubsetsThatSumToKHelper(vector<int>& arr, vector<vector<int>> &ans, vector<int> curSubset, int k, int idx)
{
    if (idx == arr.size())
    {
        if (k == 0 && curSubset.size() != 0)
        {
            ans.push_back(curSubset);
        }
        return;
    }

    findSubsetsThatSumToKHelper(arr, ans, curSubset, k, idx + 1);
    curSubset.push_back(arr[idx]);
    findSubsetsThatSumToKHelper(arr, ans, curSubset, k - arr[idx], idx + 1);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr,int n, int k)
{

    vector<vector<int>> ans;
    vector<int> curSubset;
    findSubsetsThatSumToKHelper(arr, ans, curSubset, k, 0);
    return ans;
}
