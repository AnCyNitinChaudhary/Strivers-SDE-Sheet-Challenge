#include <bits/stdc++.h> 
long getTrappedWater(long *height, int n){
    // Write your code here.
    //Approach using largest prefix array and largest suffix array.
        // vector<long>pre(n,0);
        // vector<long>suf(n,0);
        // pre[0]=height[0];
        // for(long i=1;i<n;i++){
        //     pre[i]=max(pre[i-1],height[i]);
        // }
        // suf[n-1]=height[n-1];
        //  for(int i=n-2;i>=0;i--){
        //     suf[i]=max(suf[i+1],height[i]);
        // }
        // long ans=0;
        // for(long i=0;i<n;i++){
        //     if(i!=0&&i!=n-1)ans+=min(pre[i],suf[i])-height[i];
        // }
        // return ans;
        //The above code is working successfully and I have written the above code by my own 
        //Without using extra memory as taught by the striver.
        long left=0;
        long right=n-1;
        long answer=0;
        long maxleft=0;
        long maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft)maxleft=height[left];
                else answer+=maxleft-height[left];
                left++;
            }
            else{
                if(height[right]>=maxright)maxright=height[right];
                else answer+=maxright-height[right];
            right--;
            }
        }
        return answer;
}
