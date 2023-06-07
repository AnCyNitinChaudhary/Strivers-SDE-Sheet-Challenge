#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    priority_queue<pair<int,int>>pq;
    int profit=0;
    int maxiDeadline=INT_MIN;
    for(int i=0;i<n;i++){
        pq.push({jobs[i][1],jobs[i][0]});
        maxiDeadline=max(maxiDeadline,jobs[i][0]);
    }
    vector<bool>booked(maxiDeadline+1,false);
    while(!pq.empty()){
        int dead=pq.top().second;
        while(dead>0){
            if(booked[dead]==false){
                booked[dead]=true;
                profit+=pq.top().first;
                break;
            }
            else dead--;
        }
        pq.pop();
    }
    return profit;
    //I am happy that this code is working fine and I have done this code very easily due to understanding in APS classroom.
    // Write your code here
    
}
