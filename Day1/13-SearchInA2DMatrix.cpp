
bool binarySearchit(vector<vector<int>>&mat,int target,int left,int right,int col){
    if(left<=right){
        int mid=(left+right)/2;
        if(mat[mid/col][mid%col]==target)return true;
        else if(mat[mid/col][mid%col]<target)return binarySearchit(mat,target,mid+1,right,col);
        else return binarySearchit(mat,target,left,mid-1,col);
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& mat, int target) {
        //This problem can be easily solved using the binary search method such that the 2D matrix will be treated as 1D matrix 
        //To do so - I have to use rowNum=index/m and colNum=index%m; where m is the column number
        int left=0;
        int n=mat.size();
        int m=mat[0].size();
        int right=(n*m)-1;
        bool answer= binarySearchit(mat,target,left,right,m);
        return answer;

}
