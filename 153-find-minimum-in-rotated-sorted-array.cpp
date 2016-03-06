int findMin(vector<int>& nums) {  
    if (nums.size() == 1 || nums[0] < nums.back())  
        return nums[0];  
    int i = nums.size()-1;  
    while(nums[i] > nums[i-1]) i--;  
    return nums[i];  
}  