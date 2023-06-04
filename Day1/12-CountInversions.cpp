#include <bits/stdc++.h> 
// int answer=0;
// void merge(long long *arr,int l,int m,int r){
//         vector<int> v1={arr+l, arr+m+1};
//          vector<int> v2={arr+m+1, arr+r+1};
//          int i=l, j=0, k=0;
//          while(j<v1.size() && k<v2.size()){
//              if(v1[j]<=v2[k])
//              {
//                  arr[i++]=v1[j++];

//              } else {
//                 answer+=(m-j+1);
//                arr[i++] = v2[k++];
//              }
//          }
         
//          while(j<v1.size()){
//              arr[i++]=v1[j++];
//          }
//          while(k<v2.size()){
//              arr[i++]=v2[k++];
//          }
// }
// void mergeSort(long long *arr,int left,int right){
//     if(left<right){
//         int mid=(left+right)/2;
//         mergeSort(arr,left,mid);
//         mergeSort(arr,mid+1,right);
//         merge(arr,left,mid,right);
//     }
// }
long long getInversions(long long *arr, int n){
    // Write your code here.
    //Brute force appraoch
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])ans++;
        }
    }
    return ans;
    //This problem can be solved in O(nlogn) time complexity using the concept of merge sort.
    //The implementation is given below-
    //I am going to implement this without any help
    // int i=0;
    // mergeSort(arr,0,n-1);
    // return answer;
    //Merge sort approach is giving some error while the brute force is working successfully.
}
