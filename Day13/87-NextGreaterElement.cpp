#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int>ans(n);
    // ans[n-1]=-1;
    // // priority_queue<int>pq;
    // // pq.push(arr[n-1]);
    // for(int i=n-2;i>=0;i--){
    //     int maxi=-1;
    // for(int j=i+1;j<n;j++){
    //     if(arr[j]>arr[i]){
    //         maxi=arr[j];
    //         break;
    //     }
    // }
    // ans[i]=maxi;
    // }
    // return ans;
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = -1;
        } 
        else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }
    return ans;
}
