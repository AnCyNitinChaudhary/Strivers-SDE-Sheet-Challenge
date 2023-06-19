int binarySearch(vector<int>&arr,int left,int right,int n){
  if (left <= right) {
    int mid = (left + right) / 2;
	if(mid==0){
		if(arr[mid]!=arr[mid+1])return arr[mid];
	}
	else if(mid==n-1){
		if(arr[mid]!=arr[mid-1])return arr[mid];
	}
	else if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1])return arr[mid];
	else if(arr[mid]==arr[mid+1]){
		if(mid%2==0)return binarySearch(arr,mid+2,right,n);
		else return binarySearch(arr,left,mid-1,n);
	}
	else if(arr[mid]==arr[mid-1]){
		if(mid%2==0)return binarySearch(arr,left,mid-2,n);
		else return binarySearch(arr,mid+1,right,n);
	}
  }
  return -1;
}

int singleNonDuplicate(vector<int>& arr)
{
	// int i=0;
	int n=arr.size();
	// while(i<n-1){
	// 	if(arr[i]!=arr[i+1])return arr[i];
	// 	else i+=2;
	// }
	// return arr[n-1];
	//The above solution gives TLE
	// int result=0;
	// for(int i=0;i<n;i++)result^=arr[i];
	// return result;
	if(n==1)return arr[0];
	int answer=binarySearch(arr,0, n-1, n);
	return answer;
	// Write your code here
}
