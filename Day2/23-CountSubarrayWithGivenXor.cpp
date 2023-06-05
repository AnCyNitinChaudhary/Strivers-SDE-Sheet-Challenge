#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    //Hack understood from striver similar to sum k like question
    //let the xor till some ending point is xe during traversal
    //Let us assume that there exist some elemnts in between which has xor as x
    /*
    Let p be the xor which is already known for other than elements giving xor as x, during traversal and stored in unordered map.
    p^x=xe
    p^x^x=xe^k
    p=xe^x
    It means if I will store already p and again got the same xor this means I am having a subarray in betweeen which results in xor k, So, I can do count+=um[p]
    In last I can return the count.
    */
    unordered_map<int,int>um;//to store p with it's count
    um[0]=1;
    int xe=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        xe^=arr[i];
        int p=xe^x;
        if(um.find(p)!=um.end())count+=um[p];
        um[xe]++;
    }
    return count;

}
