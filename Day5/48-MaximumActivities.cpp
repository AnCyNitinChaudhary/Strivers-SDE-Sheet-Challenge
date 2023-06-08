#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    for(int i=0;i<n;i++){
            pq.push(make_pair(finish[i],start[i]));
    }
        int count=1;
        int en=pq.top().first;
        pq.pop();
        while(!pq.empty()){
            int st=pq.top().second;
            if(st>=en){
                count++;
                en=pq.top().first;
            }
            pq.pop();
        }
        return count;
}
