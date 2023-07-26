#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int>um;
//      priority_queue<pair<int,int>,vector<pair<int,int>> >pq;
    for(int i=0;i<n;i++){
        um[arr[i]]++;
    }
//     for(int i=0;i<n;i++){
//         pq.push({um[arr[i]],arr[i]});
//     }
//     vector<int>ans;
//     while(k--){
//         ans.push_back(pq.top().first);
//         pq.pop();
//     }
//     return ans;
vector<int> bucket[n + 1];

    for (auto x : um)
    {
        int freq = x.second;

        // Add in correct bucket.
        bucket[freq].push_back(x.first);
    }

    vector<int> ans(k);
    int cur = 0;

    for (int i = n; i > 0 && k > 0; i--)
    {
        if (bucket[i].size() == 0)
        {
            continue;
        }

        for (int num : bucket[i])
        {

            ans[cur++] = num;
            k--;
            if (k == 0)
            {
                break;
            }
        }
    }

    return ans;
}
