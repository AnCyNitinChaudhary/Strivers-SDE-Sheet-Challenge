int maximumXor(vector<int> A)
{
    int n=A.size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=max(ans,A[i]^A[j]);
        }
    }
    return ans;
    // Write your code here.   
}
