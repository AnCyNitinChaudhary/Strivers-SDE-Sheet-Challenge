#include <bits/stdc++.h> 
bool possible(int i,vector<vector<int>>&mat,int c,int color[]){
    for(int j=0;j<mat[0].size();j++){
        if(mat[i][j]){
            if(color[j]==c)return false;
        }
    }
    return true;
}
bool solve(int i,vector<vector<int>>&mat,int color[],int n,int m){
    if(i==n)return "YES";
    //if(color[i]!=0)return solve(i+1,mat,color,n,m);
    for(int c=1;c<=m;c++){
        if(possible(i,mat,c,color)){
            color[i]=c;
            if(solve(i+1,mat,color,n,m))return true;
            color[i]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    int color[n]={0};
    if(solve(0,mat,color,n,m))return "YES";
    return "NO";
}
