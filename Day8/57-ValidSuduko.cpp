
    bool isValid(int board[9][9],int row,int col,int c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c)return false;
            if(board[row][i]==c)return false;
        }
        int startrow=3*(row/3);
        int startcol=3*(col/3);
        for(int i=startrow;i<startrow+3;i++){
            for(int j=startcol;j<startcol+3;j++){
                if(board[i][j]==c)return false;
            }
        }
        return true;
    }
    bool solve(int board[9][9]){
            for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]==0){
                    for(int c=1;c<=9;c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board))return true;
                            else board[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
bool isItSudoku(int matrix[9][9]) {
    return solve(matrix);
}
