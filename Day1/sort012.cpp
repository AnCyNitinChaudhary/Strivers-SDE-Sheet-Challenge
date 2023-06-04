#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //The simple approach which is to be coming in my brain is that I can just count the occurences of all these three colors and then override the values according to the count. This solution is implemented below.
       int c0=0;
       int c1=0;
       int c2=0;
       for(int i=0;i<n;i++){
           if(arr[i]==0)c0++;
           if(arr[i]==1)c1++;
           if(arr[i]==2)c2++;
       }
       for(int i=0;i<c0;i++)arr[i]=0;
       for(int i=c0;i<c0+c1;i++)arr[i]=1;
       for(int i=c0+c1;i<c0+c1+c2;i++)arr[i]=2;
   //   Write your code here
}
