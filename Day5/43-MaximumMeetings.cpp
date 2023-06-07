#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    //The intution behind this problem is that try to complete that meeting at first which is completing at earliest.
    //for this I can use priority_queue.
    // map<pair<int,int>,int>um;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    // int n=start.size();
    // for(int i=0;i<n;i++){
    //   pq.push({end[i], start[i]});
    //   um[{end[i], start[i]}]=i+1;
    // }
    // int en=pq.top().first;
    // vector<int>ans;
    // ans.push_back(um[{en,pq.top().second}]);
    // while(!pq.empty()){
    //     int start=pq.top().second;
    //     if(start>en){
    //         ans.push_back(um[{en,start}]);
    //         en=pq.top().first;
    //     }
    //     pq.pop();
    // }
    // sort(ans.begin(),ans.end());
    // return ans;
    

    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
    int n=start.size();
    for(int i=0;i<n;i++){
      pq.push({{end[i], i+1},start[i]});
    }
    int en=pq.top().first.first;
    vector<int>ans;
    ans.push_back(pq.top().first.second);
    while(!pq.empty()){
        int start=pq.top().second;
        if(start>en){
            ans.push_back(pq.top().first.second);
            en=pq.top().first.first;
        }
        pq.pop();
    }
    //sort(ans.begin(),ans.end());
    return ans;
    //I am feeling very proud as I have solved this problem by my own.
    
}
