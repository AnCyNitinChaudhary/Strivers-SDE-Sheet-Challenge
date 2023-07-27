#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    // int n = nums.size();
    // map<int, int> window;
    // for (int i = 0; i < k - 1; i++)
    // {
    //     window[nums[i]]++;
    // }
    // vector<int> windowMax(n - k + 1, 0);
    // for (int high = k - 1; high < n; high++)
    // {
    //     window[nums[high]] = window[nums[high]] + 1;
    //     windowMax[high - k + 1] = (window.rbegin())->first;
    //     if (window[nums[high - k + 1]] == 1)
    //     {
    //         window.erase(nums[high - k + 1]);
    //     }
    //     else
    //     {
    //         window[nums[high - k + 1]]--;
    //     }
    // }
    // return windowMax;

    deque<int> window(k);

    int n = nums.size();

    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        while ((!window.empty()) && nums[i] >= nums[window.back()])
        {
            window.pop_back();
        }
        window.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        result.push_back(nums[window.front()]);
        while ((!window.empty()) && window.front() <= i - k)
        {
            window.pop_front();
        }
        while ((!window.empty()) && nums[i] >= nums[window.back()])
        {
            window.pop_back();
        }
        window.push_back(i);
    }
    result.push_back(nums[window.front()]);
    return result;
}
