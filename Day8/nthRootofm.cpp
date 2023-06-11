#include<math.h>

int binarySearch(int left,int right,int n,int m){
  if(left<=right){
    int mid=(left+right)/2;
    //long long p=1LL*pow(mid,n);
    if(pow(mid,n)==m)return mid;
    else if(pow(mid,n)>m)return binarySearch(left,mid-1,n,m);
    else return binarySearch(mid+1, right, n, m);
  }
  return -1;
}
int NthRoot(int n, int m){
//NthRoot of m will be that number if we do power of this number to n then we will get m
//We can apply binary search to this as we know min and max limit.
int right=m;
int left=1;
int answer=binarySearch(left,right,n,m);
return answer;
// Write your code here.
}
