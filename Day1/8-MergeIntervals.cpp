#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Solved by me without any help
     if(intervals.size()==0)return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);
        for(int i=1;i<intervals.size();i++){
            if(temp[0]>intervals[i][0])temp[0]=intervals[i][0];
            if(temp[1]<intervals[i][0]){
                ans.push_back(temp);
                temp[0]=intervals[i][0];
                temp[1]=intervals[i][1];
            }
            else if(temp[1]<intervals[i][1])temp[1]=intervals[i][1];
        }
    ans.push_back(temp);
    return ans;
}
