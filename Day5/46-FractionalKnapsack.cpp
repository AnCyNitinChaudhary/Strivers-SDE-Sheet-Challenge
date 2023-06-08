#include <bits/stdc++.h> 
bool com(const pair<int, int>& p1, const pair<int, int>& p2) {
        return ((1.0*p1.second)/p1.first) >= ((1.0*p2.second)/p2.first);
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),com);
    double value=0;
    int i=0;
    while(w&&i<items.size()){
        if(items[i].first<=w){
            w-=items[i].first;
            value+=items[i].second;
            i++;
        }
        else{
            value+=(w*items[i].second*1.0)/(items[i].first*1.0);
            w=0;
            i++;
        }
    }
    return value;

    //After solving this problem. A happy feeling is coming in my brain.
    
}
