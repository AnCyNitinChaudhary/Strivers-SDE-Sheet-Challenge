int removeDuplicates(vector<int> &nums, int n) {
	// Write your code here.
	int currentindex=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])continue;
            nums[currentindex++]=nums[i];
        }
    return currentindex;
}
