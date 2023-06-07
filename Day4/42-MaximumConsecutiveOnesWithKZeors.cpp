int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    // int currentcount=0;
    //     int temp=0;
    //     int numof0=0;
    //     for(int i=0;i<n;i++){
    //         int j=i;
    //         while(j<n){
    //         if(arr[j]==1)temp++;
    //         else if(numof0<k){
    //             temp++;
    //             numof0++;
    //         } else {
    //           temp = 0;
    //           numof0 = 0;
    //           break;
    //         }
    //         j++;
    //         }
    //         currentcount=max(currentcount,temp);
    //     }
    // return currentcount;
    //Adopt the below method of solving the sliding window problem
     int i=0,j=0,count0=0,ans=0;
        while(j<n){
            if(arr[j]==0)count0++;
            while(count0>k&&i<n){
                if(arr[i]==0)count0--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
}
