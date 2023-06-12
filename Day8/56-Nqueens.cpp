
    bool isSafe(int row,int col,vector<vector<int>>&board,int n){
        int temprow=row;
        int tempcol=col;
        while(row>=0&&col>=0){
            if(board[row][col]==1)return false;
            row--;
            col--;
        }
        row=temprow;
        col=tempcol;
        while(row<n&&col>=0){
            if(board[row][col]==1)return false;
            row++;
            col--;
        }
        while(tempcol>=0){
            if(board[temprow][tempcol]==1)return false;
            tempcol--;
        }
        return true;
    }
    void addSolution(vector < vector < int >> & board, int n, vector < vector < int >> & ans) {
    vector < int > currentAnswer;
    for (auto x: board) {
        for (auto y: x) {
            currentAnswer.push_back(y);
        }
    }
    ans.push_back(currentAnswer);
}
    void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n){
        if(col==n){
            addSolution(board,n,ans);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]=1;
                solve(col+1,board,ans,n);
                board[row][col]=0;
            }
        }
    }
    vector<vector<int>> solveNQueens(int n) {
      vector<vector<int>> ans;
      vector<vector<int>> board(n, vector<int>(n, 0));
      solve(0, board, ans, n);
      return ans;
    }
