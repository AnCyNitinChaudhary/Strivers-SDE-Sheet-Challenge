//Brute Force
#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    vector<int>temp;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp.push_back(matrix[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    if(temp.size()%2==0)return temp[temp.size()/2];
    return temp[((temp.size())/2)];
}
