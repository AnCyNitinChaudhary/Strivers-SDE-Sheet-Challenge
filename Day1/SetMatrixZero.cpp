#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	 vector<pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                    //cout<<"Entered"<<i<<j;
                }
            }
        }
        for(auto index:v){
            //cout<<index.first<<endl<<index.second;
            for(int j=0;j<matrix[0].size();j++){
                matrix[index.first][j]=0;
            }
            for (int i = 0; i < matrix.size(); i++) {
              matrix[i][index.second] = 0;
            }
        }
}
