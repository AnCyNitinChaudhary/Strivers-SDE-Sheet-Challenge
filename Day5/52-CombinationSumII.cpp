#include<bits/stdc++.h>
using namespace std;
//   void f(int i,vector<int>&v,int t,set<vector<int>>&us,vector<int>&temp,int sum){
//         if(sum==t){
//             us.insert(temp);
//             return;
//         }
//         if(i<0||sum>t)return;
//         //not take
//         f(i-1,v,t,us,temp,sum);
//         //take
//         temp.push_back(v[i]);
//         f(i-1,v,t,us,temp,sum+v[i]);
//         temp.pop_back();
//     }
 void recur(int i, int t, vector<int> &v, vector<int> &temp, set<vector<int>> &ans){
      if(t == 0){
        ans.insert(temp);
        return;
      }
      for(int idx = i; idx < v.size(); idx++){
        if(idx > i and v[idx] == v[idx - 1]) continue;
        if(t - v[idx] < 0) break;
        temp.emplace_back(v[idx]);
        recur(idx + 1, t - v[idx], v, temp, ans);
        temp.pop_back();
      }
    }
vector<vector<int>> combinationSum2(vector<int> &v, int n, int t)
{
	// sort(v.begin(),v.end());
    // set<vector<int>>us;
    // vector<int>temp;
    // f(n-1,v,t,us,temp,0);
    // vector<vector<int>>ans(us.begin(),us.end());
    // return ans;
    //This type of template is always giving wrong answer.
    //I must have to understand that this comes under backtracking category, so I must adapt that template.
       set<vector<int>> anst;
      vector<int> temp;
      sort(v.begin(), v.end());
      recur(0, t, v, temp, anst);
      vector<vector<int>> ans(anst.begin(), anst.end());
      return ans;

	// Write your code here.
}
