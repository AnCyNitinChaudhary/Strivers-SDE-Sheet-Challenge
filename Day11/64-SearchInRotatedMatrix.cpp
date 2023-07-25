int search(int* arr, int n, int key) {
    // Write your code here.
    //The idea is to handle the sorted part.
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==key)return mid;
        else if(arr[left]<=arr[mid]){
            if(arr[left]<=key&&arr[mid]>=key)right=mid-1;
            else left=mid+1;
        }
        else{
            if(arr[mid]<=key&&arr[right]>=key)left=mid+1;
            else right=mid-1;
        }
    }
    return -1;
}
