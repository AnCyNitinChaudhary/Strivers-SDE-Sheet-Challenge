#include <bits/stdc++.h>
int countme(int arr[],int n,int target){
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]==target)count++;
	}
	return count;
}
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	 //This can be solved by moore voting algorithm in which we just store the element when it makes count as 0.
	 	if(n==0)return -1;
	   int element;
        int count=0;
        for(int i=0;i<n;i++) {
            if(count==0)element=arr[i];
            if(arr[i]==element)count++;
            else count--;
        }
        if(countme(arr,n,element)<=floor(n/2.0))return -1;
		return element;

}
