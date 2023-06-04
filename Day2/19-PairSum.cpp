#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   // unordered_map<int,int>um;
   // vector<vector<int>> ans;
   // for(auto i:arr){
   //    um[i]++;
   //    if(um.find(s-i)!=um.end()){
   //       vector<int>temp;
   //       if(i<(s-i)){
   //          temp.push_back(i);
   //          temp.push_back(s-i);
   //          ans.push_back(temp);
   //       }
   //       else{
   //          temp.push_back(s-i);
   //          temp.push_back(i);
   //          ans.push_back(temp);
   //       }
   //    }
   // }
   // sort(ans.begin(),ans.end());
   // return ans;

   // unordered_map<int,int>um;
   // vector<vector<int>> ans;
   // for (auto i : arr) {
   //   um[i]++;
   // }
   // for (auto i : um) {
   //    if(um.find(s-i.first)!=um.end()){
   //       vector<int>temp;
   //       if(i.first<(s-i.first)){
   //          temp.push_back(i.first);
   //          temp.push_back(s-i.first);
   //          ans.push_back(temp);
   //       }
   //       else{
   //          temp.push_back(s-i.first);
   //          temp.push_back(i.first);
   //          ans.push_back(temp);
   //       }
   //       um.erase(i.first);
   //    }
   // }
   // sort(ans.begin(),ans.end());
   // return ans;




   // unordered_set<int>us;
   // vector<vector<int>> ans;
   // for (auto i : arr) {
   //   us.insert(i);
   // }
   // for (auto it=us.begin();it!=us.end();it++) {
   //    int i=*it;
   //    if(us.find(s-i)!=us.end()){
   //       vector<int>temp;
   //       if(i<(s-i)){
   //          temp.push_back(i);
   //          temp.push_back(s-i);
   //          ans.push_back(temp);
   //       }
   //       else{
   //          temp.push_back(s-i);
   //          temp.push_back(i);
   //          ans.push_back(temp);
   //       }
   //       us.erase(it);
   //       //it--;
   //       //us.erase(us.find(s-i));
   //       //it--;
   //    }
   // }
   // sort(ans.begin(),ans.end());
   // return ans;


   
    int n = arr.size();
    map<int, int> um;
    vector<vector<int>> ans;
    for (int i : arr)
    {
        int count = um[s - i];
        vector<int> temp(2);
        temp[0]=i;
        temp[1]=s - i;

        while (count--)
        {
            ans.push_back(temp);
        }

        um[i]++;
    }

    vector<vector<int>> res(ans.size(), vector<int>(2, 0));
    for (int i = 0; i < ans.size(); i++)
    {
        int a = ans[i][0], b = ans[i][1];
        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }
    sort(res.begin(), res.end());
    return res;
}
