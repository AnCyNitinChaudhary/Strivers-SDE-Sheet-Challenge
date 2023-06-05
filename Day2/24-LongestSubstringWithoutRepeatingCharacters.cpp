#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    //The idea is to use hashmap and sliding window as taught by striver
    int left=0;
    unordered_map<char,int>um;
    int len=0;
    for(int right=0;right<input.size();right++){
        if(um.find(input[right])!=um.end())left=max(left,um[input[right]]+1);  
        um[input[right]]=right;
        len=max(len,right-left+1);
    }
    return len;

}
